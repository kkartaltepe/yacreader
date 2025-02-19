#ifndef SHORTCUTS_MANAGER_H
#define SHORTCUTS_MANAGER_H

#include <QObject>
#include <QKeySequence>
#include <QString>
#include <QMap>

class QAction;

// QAction: used setData() and data() for storing (userData) an identifier for each QAction. This value is ussed in QSettings

class ShortcutsManager
{
private:
    ShortcutsManager();
    QMap<QString, QKeySequence> defaultShorcuts;
    QList<QAction *> actions; // all actions registered, used for checking conflicts

    void initDefaultShorcuts();

public:
    static ShortcutsManager &getShortcutsManager()
    {
        static ShortcutsManager manager;
        return manager;
    }

    void resetToDefaults();
    QString getShortcut(const QString &name);
    void saveShortcut(QAction *action);
    void registerActions(const QList<QAction *> &actions);
    bool checkConflicts(const QKeySequence &shortcut, const QAction *dest);
};

// ACTION NAMES YACReaderLibrary
#define BACK_ACTION_YL "BACK_ACTION_YL"
#define FORWARD_ACTION_YL "FORWARD_ACTION_YL"
#define CREATE_LIBRARY_ACTION_YL "CREATE_LIBRARY_ACTION_YL"
#define OPEN_LIBRARY_ACTION_YL "OPEN_LIBRARY_ACTION_YL"
#define EXPORT_COMICS_INFO_ACTION_YL "EXPORT_COMICS_INFO_ACTION_YL"
#define IMPORT_COMICS_INFO_ACTION_YL "IMPORT_COMICS_INFO_ACTION_YL"
#define EXPORT_LIBRARY_ACTION_YL "EXPORT_LIBRARY_ACTION_YL"
#define IMPORT_LIBRARY_ACTION_YL "IMPORT_LIBRARY_ACTION_YL"
#define UPDATE_LIBRARY_ACTION_YL "UPDATE_LIBRARY_ACTION_YL"
#define RENAME_LIBRARY_ACTION_YL "RENAME_LIBRARY_ACTION_YL"
#define REMOVE_LIBRARY_ACTION_YL "REMOVE_LIBRARY_ACTION_YL"
#define RESCAN_LIBRARY_XML_INFO_ACTION_YL "RESCAN_LIBRARY_XML_INFO_ACTION_YL"
#define OPEN_COMIC_ACTION_YL "OPEN_COMIC_ACTION_YL"
#define SET_AS_READ_ACTION_YL "SET_AS_READ_ACTION_YL"
#define SET_AS_NON_READ_ACTION_YL "SET_AS_NON_READ_ACTION_YL"
#define SET_AS_MANGA_ACTION_YL "SET_AS_MANGA_ACTION_YL"
#define SET_AS_NORMAL_ACTION_YL "SET_AS_MANGA_ACTION_YL"
#define SET_AS_WESTERN_MANGA_ACTION_YL "SET_AS_WESTERN_MANGA_ACTION_YL"
#define SET_AS_WEB_COMIC_ACTION_YL "SET_AS_WEB_COMIC_ACTION_YL"
#define SET_AS_YONKOMA_ACTION_YL "SET_AS_YONKOMA_ACTION_YL"
#define SHOW_HIDE_MARKS_ACTION_YL "SHOW_HIDE_MARKS_ACTION_YL"
#define TOGGLE_FULL_SCREEN_ACTION_YL "TOGGLE_FULL_SCREEN_ACTION_YL"
#define HELP_ABOUT_ACTION_YL "HELP_ABOUT_ACTION_YL"
#define SET_ROOT_INDEX_ACTION_YL "SET_ROOT_INDEX_ACTION_YL"
#define EXPAND_ALL_NODES_ACTION_YL "EXPAND_ALL_NODES_ACTION_YL"
#define COLAPSE_ALL_NODES_ACTION_YL "COLAPSE_ALL_NODES_ACTION_YL"
#define OPTIONS_ACTION_YL "OPTIONS_ACTION_YL"
#define SERVER_CONFIG_ACTION_YL "SERVER_CONFIG_ACTION_YL"
#define TOGGLE_COMICS_VIEW_ACTION_YL "TOGGLE_COMICS_VIEW_ACTION_YL"
#define OPEN_CONTAINING_FOLDER_ACTION_YL "OPEN_CONTAINING_FOLDER_ACTION_YL"
#define SET_FOLDER_AS_NOT_COMPLETED_ACTION_YL "SET_FOLDER_AS_NOT_COMPLETED_ACTION_YL"
#define SET_FOLDER_AS_COMPLETED_ACTION_YL "SET_FOLDER_AS_COMPLETED_ACTION_YL"
#define SET_FOLDER_AS_READ_ACTION_YL "SET_FOLDER_AS_READ_ACTION_YL"
#define SET_FOLDER_AS_UNREAD_ACTION_YL "SET_FOLDER_AS_UNREAD_ACTION_YL"
#define SET_FOLDER_AS_MANGA_ACTION_YL "SET_FOLDER_AS_MANGA_ACTION_YL"
#define SET_FOLDER_AS_WESTERN_MANGA_ACTION_YL "SET_FOLDER_AS_WESTERN_MANGA_ACTION_YL"
#define SET_FOLDER_AS_NORMAL_ACTION_YL "SET_FOLDER_AS_NORMAL_ACTION_YL"
#define SET_FOLDER_AS_WEB_COMIC_ACTION_YL "SET_FOLDER_AS_WEB_COMIC_ACTION_YL"
#define SET_FOLDER_AS_YONKOMA_ACTION_YL "SET_FOLDER_AS_YONKOMA_ACTION_YL"
#define OPEN_CONTAINING_FOLDER_COMIC_ACTION_YL "OPEN_CONTAINING_FOLDER_COMIC_ACTION_YL"
#define RESET_COMIC_RATING_ACTION_YL "RESET_COMIC_RATING_ACTION_YL"
#define SELECT_ALL_COMICS_ACTION_YL "SELECT_ALL_COMICS_ACTION_YL"
#define EDIT_SELECTED_COMICS_ACTION_YL "EDIT_SELECTED_COMICS_ACTION_YL"
#define ASIGN_ORDER_ACTION_YL "ASIGN_ORDER_ACTION_YL"
#define FORCE_COVER_EXTRACTED_ACTION_YL "FORCE_COVER_EXTRACTED_ACTION_YL"
#define DELETE_METADATA_FROM_COMICS_ACTION_YL "DELETE_METADATA_FROM_COMICS_ACTION_YL"
#define DELETE_COMICS_ACTION_YL "DELETE_COMICS_ACTION_YL"
#define HIDE_COMIC_VIEW_ACTION_YL "HIDE_COMIC_VIEW_ACTION_YL"
#define GET_INFO_ACTION_YL "GET_INFO_ACTION_YL"
#define FOCUS_SEARCH_LINE_ACTION_YL "FOCUS_SEARCH_LINE_ACTION_YL"
#define FOCUS_COMICS_VIEW_ACTION_YL "FOCUS_COMICS_VIEW_ACTION_YL"
#define SHOW_EDIT_SHORTCUTS_ACTION_YL "SHOW_EDIT_SHORTCUTS_ACTION_YL"
#define QUIT_ACTION_YL "QUIT_ACTION_YL"
#define UPDATE_CURRENT_FOLDER_ACTION_YL "UPDATE_CURRENT_FOLDER_ACTION_YL"
#define SCAN_XML_FROM_CURRENT_FOLDER_ACTION_YL "SCAN_XML_FROM_CURRENT_FOLDER_ACTION_YL"
#define ADD_FOLDER_ACTION_YL "ADD_FOLDER_ACTION_YL"
#define REMOVE_FOLDER_ACTION_YL "REMOVE_FOLDER_ACTION_YL"
#define ADD_READING_LIST_ACTION_YL "ADD_READING_LIST_ACTION_YL"
#define REMOVE_READING_LIST_ACTION_YL "REMOVE_READING_LIST_ACTION_YL"
#define ADD_LABEL_ACTION_YL "ADD_LABEL_ACTION_YL"
#define RENAME_LIST_ACTION_YL "RENAME_LIST_ACTION_YL"
#define ADD_TO_FAVORITES_ACTION_YL "ADD_TO_FAVORITES_ACTION_YL"
#define SAVE_COVERS_TO_ACTION_YL "SAVE_COVERS_TO_ACTION_YL"
#define SHOW_HIDE_RECENT_INDICATOR_ACTION_YL "SHOW_HIDE_RECENT_INDICATOR_ACTION_YL"
// COMMANDS YACReaderLibrary

// ACTION NAMES YACReader
#define OPEN_ACTION_Y "OPEN_ACTION_Y"
#define NEW_INSTANCE_ACTION_Y "NEW_INSTANCE_ACTION_Y"
#define OPEN_FOLDER_ACTION_Y "OPEN_FOLDER_ACTION_Y"
#define SAVE_IMAGE_ACTION_Y "SAVE_IMAGE_ACTION_Y"
#define OPEN_PREVIOUS_COMIC_ACTION_Y "OPEN_PREVIOUS_COMIC_ACTION_Y"
#define OPEN_NEXT_COMIC_ACTION_Y "OPEN_NEXT_COMIC_ACTION_Y"
#define PREV_ACTION_Y "PREV_ACTION_Y"
#define NEXT_ACTION_Y "NEXT_ACTION_Y"
#define ADJUST_HEIGHT_ACTION_Y "ADJUST_HEIGHT_Y"
#define ADJUST_WIDTH_ACTION_Y "ADJUST_WIDTH_Y"
#define LEFT_ROTATION_ACTION_Y "LEFT_ROTATION_ACTION_Y"
#define RIGHT_ROTATION_ACTION_Y "RIGHT_ROTATION_ACTION_Y"
#define DOUBLE_PAGE_ACTION_Y "DOUBLE_PAGE_ACTION_Y"
#define DOUBLE_MANGA_PAGE_ACTION_Y "DOUBLE_MANGA_PAGE_ACTION_Y"
#define GO_TO_PAGE_ACTION_Y "GO_TO_PAGE_ACTION_Y"
#define OPTIONS_ACTION_Y "OPTIONS_ACTION_Y"
#define HELP_ABOUT_ACTION_Y "HELP_ABOUT_ACTION_Y"
#define SHOW_MAGNIFYING_GLASS_ACTION_Y "SHOW_MAGNIFYING_GLASS_ACTION_Y"
#define SET_BOOKMARK_ACTION_Y "SET_BOOKMARK_ACTION_Y"
#define SHOW_BOOKMARKS_ACTION_Y "SHOW_BOOKMARKS_ACTION_Y"
#define SHOW_SHORCUTS_ACTION_Y "SHOW_SHORCUTS_ACTION_Y"
#define SHOW_INFO_ACTION_Y "SHOW_INFO_ACTION_Y"
#define CLOSE_ACTION_Y "CLOSE_ACTION_Y"
#define SHOW_DICTIONARY_ACTION_Y "SHOW_DICTIONARY_ACTION_Y"
#define ADJUST_TO_FULL_SIZE_ACTION_Y "ADJUST_TO_FULL_SIZE_ACTION_Y"
#define FIT_TO_PAGE_ACTION_Y "FIT_TO_PAGE_ACTION_Y"
#define SHOW_FLOW_ACTION_Y "SHOW_FLOW_ACTION_Y"
#define SHOW_EDIT_SHORTCUTS_ACTION_Y "SHOW_EDIT_SHORTCUTS_ACTION_Y"
#define OPEN_LATEST_COMIC_Y "OPEN_LATEST_COMIC_Y"

// COMMANDS YACReader
// main_viewer_window
#define TOGGLE_FULL_SCREEN_ACTION_Y "TOGGLE_FULL_SCREEN_ACTION_Y"
#define TOGGLE_TOOL_BARS_ACTION_Y "TOGGLE_TOOL_BARS_ACTION_Y"
#define CHANGE_FIT_ACTION_Y "CHANGE_FIT_ACTION_Y"
#define ZOOM_PLUS_ACTION_Y "ZOOM_PLUS_ACTION_Y"
#define ZOOM_MINUS_ACTION_Y "ZOOM_MINUS_ACTION_Y"
#define RESET_ZOOM_ACTION_Y "RESET_ZOOM_ACTION_Y"
// viewer
#define AUTO_SCROLL_FORWARD_ACTION_Y "AUTO_SCROLL_FORWARD_ACTION_Y"
#define AUTO_SCROLL_BACKWARD_ACTION_Y "AUTO_SCROLL_BACKWARD_ACTION_Y"
#define AUTO_SCROLL_FORWARD_VERTICAL_FIRST_ACTION_Y "AUTO_SCROLL_FORWARD_VERTICAL_FIRST_ACTION_Y"
#define AUTO_SCROLL_BACKWARD_VERTICAL_FIRST_ACTION_Y "AUTO_SCROLL_BACKWARD_VERTICAL_FIRST_ACTION_Y"
#define AUTO_SCROLL_FORWARD_HORIZONTAL_FIRST_ACTION_Y "AUTO_SCROLL_FORWARD_HORIZONTAL_FIRST_ACTION_Y"
#define AUTO_SCROLL_BACKWARD_HORIZONTAL_FIRST_ACTION_Y "AUTO_SCROLL_BACKWARD_HORIZONTAL_FIRST_ACTION_Y"
#define MOVE_DOWN_ACTION_Y "MOVE_DOWN_ACTION_Y"
#define MOVE_UP_ACTION_Y "MOVE_UP_ACTION_Y"
#define MOVE_LEFT_ACTION_Y "MOVE_LEFT_ACTION_Y"
#define MOVE_RIGHT_ACTION_Y "MOVE_RIGHT_ACTION_Y"
#define GO_TO_FIRST_PAGE_ACTION_Y "GO_TO_FIRST_PAGE_ACTION_Y"
#define GO_TO_LAST_PAGE_ACTION_Y "GO_TO_LAST_PAGE_ACTION_Y"
// mglass
#define SIZE_UP_MGLASS_ACTION_Y "SIZE_UP_MGLASS_ACTION_Y"
#define SIZE_DOWN_MGLASS_ACTION_Y "SIZE_DOWN_MGLASS_ACTION_Y"
#define ZOOM_IN_MGLASS_ACTION_Y "ZOOM_IN_MGLASS_ACTION_Y"
#define ZOOM_OUT_MGLASS_ACTION_Y "ZOOM_OUT_MGLASS_ACTION_Y"

#endif // SHORTCUTS_MANAGER_H
