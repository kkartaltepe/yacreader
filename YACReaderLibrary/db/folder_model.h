#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include <QSortFilterProxyModel>
#include <QModelIndex>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QUrl>
#include <QIcon>

#include "folder.h"
#include "folder_query_result_processor.h"
#include "yacreader_global.h"

class FolderItem;

class FolderModelProxy : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit FolderModelProxy(QObject *parent = nullptr);
    ~FolderModelProxy() override;

    void setFilterData(QMap<unsigned long long, FolderItem *> *filteredItems, FolderItem *root);
    void clear();

    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

protected:
    FolderItem *rootItem;
    QMap<unsigned long long int, FolderItem *> filteredItems; // relación entre folders

    bool filterEnabled;
};

class FolderModel : public QAbstractItemModel
{
    Q_OBJECT

    friend class FolderModelProxy;
    friend class YACReader::FolderQueryResultProcessor;

public:
    explicit FolderModel(QObject *parent = nullptr);
    explicit FolderModel(QSqlQuery &sqlquery, QObject *parent = nullptr);
    ~FolderModel() override;

    // QAbstractItemModel methods
    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex index(qulonglong folderId) const;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;

    // Convenience methods
    void reload();
    void reload(const QModelIndex &index);
    void setupModelData(QString path);
    QString getDatabase();
    QString getFolderPath(const QModelIndex &folder);

    void updateFolderCompletedStatus(const QModelIndexList &list, bool status);
    void updateFolderFinishedStatus(const QModelIndexList &list, bool status);
    void updateFolderType(const QModelIndexList &list, YACReader::FileType type);

    QStringList getSubfoldersNames(const QModelIndex &mi);
    FolderModel *getSubfoldersModel(const QModelIndex &mi);

    Folder getFolder(const QModelIndex &mi);
    QModelIndex getIndexFromFolder(const Folder &folder, const QModelIndex &parent = QModelIndex());

    QModelIndex addFolderAtParent(const QString &folderName, const QModelIndex &parent);

    Q_INVOKABLE QUrl getCoverUrlPathForComicHash(const QString &hash) const;

    void setShowRecent(bool showRecent);
    void setRecentRange(int days);

    enum Columns {
        Name = 0,
        Path,
        Finished,
        Completed,
        Manga, // deprecated
        NumChildren,
        FirstChildHash,
        CustomImage,
        Type, // FileType
        Added,
        Updated,
    };

    enum Roles {
        FinishedRole = Qt::UserRole + 1,
        CompletedRole,
        IdRole,
        MangaRole, // deprecated
        CoverPathRole,
        FolderNameRole,
        NumChildrenRole,
        TypeRole,
        AddedRole,
        UpdatedRole,
        ShowRecentRole,
        RecentRangeRole,
    };

    bool isSubfolder;

public slots:
    void deleteFolder(const QModelIndex &mi);
    void updateFolderChildrenInfo(qulonglong folderId);

private:
    void fullSetup(QSqlQuery &sqlquery, FolderItem *parent);
    void setupModelData(QSqlQuery &sqlquery, FolderItem *parent);

    FolderItem *rootItem; // el árbol
    QMap<unsigned long long int, FolderItem *> items; // relación entre folders

    QString _databasePath;

    QIcon folderIcon;
    QIcon folderFinishedIcon;

    bool showRecent;
    qlonglong recentDays;
};

#endif
