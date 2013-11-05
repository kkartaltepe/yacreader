#ifndef COMIC_VINE_DIALOG_H
#define COMIC_VINE_DIALOG_H

#include <QDialog>

#include "comic_db.h"

class QPushButton;
class QStackedWidget;
class QLabel;
class QRadioButton;
class ComicVineClient;
class QTableView;
class TitleHeader;
class SeriesQuestion;
class SearchSingleComic;
class SearchVolume;
class SelectComic;
class SelectVolume;
class SortVolumeComics;
class QScriptValue;

//TODO this should use a QStateMachine
//----------------------------------------
class ComicVineDialog : public QDialog
{
	Q_OBJECT
public:
	explicit ComicVineDialog(QWidget *parent = 0);
	QString databasePath;
	QString basePath;
	void setComics(const QList<ComicDB> & comics);


signals:
	
public slots:
	void show();

protected slots:
	void goNext();
	void goBack();
	void debugClientResults(const QString & string);
	//show widget methods
	void showSeriesQuestion();
	void showSearchSingleComic();
	void showSearchVolume();
	void showLoading();
	void search();
	void searchVolume(const QString & v);
	void launchSearchVolume();
	void launchSearchComic();
	void showSelectVolume(const QString & json);
	void showSelectVolume();
	void showSelectComic(const QString & json);
	void showSortVolumeComics(const QString & json);
	void queryTimeOut();
    void getComicsInfo(QList<QPair<ComicDB,QString> > & matchingInfo, int count, const QString & publisher);
    ComicDB parseComicInfo(ComicDB &comic, const QString & json, int count, const QString &publisher);

private:

    QString getCharacters(const QScriptValue & json_characters);
    QMap<QString,QString> getAuthors(const QScriptValue & json_authors);

	enum ScraperMode
	{
		SingleComic,       //the scraper has been opened for a single comic
		Volume,            //the scraper is trying to get comics info for a whole volume
		SingleComicInList  //the scraper has been opened for a list of unrelated comics
	};

	enum ScraperStatus
	{
		AutoSearching,
		AskingForInfo,
		SelectingComic,
		SelectingSeries,
		SearchingSingleComic,
		SearchingVolume,
		SortingComics,
		GettingVolumeComics
	};

	ScraperMode mode;
	ScraperStatus status;

	int currentIndex;

	TitleHeader * titleHeader;

	QPushButton * skipButton;
	QPushButton * backButton;
	QPushButton * nextButton;
	QPushButton * searchButton;
	QPushButton * closeButton;

	//stacked widgets
	QStackedWidget * content;

	QWidget * infoNotFound;
	QWidget * singleComicBrowser;
	
	void doLayout();
	void doStackedWidgets();
	void doLoading();
	void doConnections();

	QList<ComicDB> comics;

	SeriesQuestion * seriesQuestionWidget;
	SearchSingleComic * searchSingleComicWidget;
	SearchVolume * searchVolumeWidget;
	SelectVolume * selectVolumeWidget;
	SelectComic * selectComicWidget;
	SortVolumeComics * sortVolumeComicsWidget;
};

#endif // COMIC_VINE_DIALOG_H
