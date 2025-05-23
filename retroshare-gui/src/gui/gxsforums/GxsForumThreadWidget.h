/*******************************************************************************
 * retroshare-gui/src/gui/gxsforums/GxsForumsThreadWidget.h                    *
 *                                                                             *
 * Copyright 2012 Retroshare Team      <retroshare.project@gmail.com>          *
 *                                                                             *
 * This program is free software: you can redistribute it and/or modify        *
 * it under the terms of the GNU Affero General Public License as              *
 * published by the Free Software Foundation, either version 3 of the          *
 * License, or (at your option) any later version.                             *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                *
 * GNU Affero General Public License for more details.                         *
 *                                                                             *
 * You should have received a copy of the GNU Affero General Public License    *
 * along with this program. If not, see <https://www.gnu.org/licenses/>.       *
 *                                                                             *
 *******************************************************************************/

#ifndef GXSFORUMTHREADWIDGET_H
#define GXSFORUMTHREADWIDGET_H

#include <QMap>

#include "gui/gxs/GxsMessageFrameWidget.h"
#include <retroshare/rsgxsforums.h>
#include "gui/gxs/GxsIdDetails.h"
#include "util/FontSizeHandler.h"

class QSortFilterProxyModel;
class QTreeWidgetItem;
class RSTreeWidgetItemCompareRole;
class GxsForumsFillThread;
class QItemSelection;
struct RsGxsForumGroup;
class RsGxsForumModel;
struct RsGxsForumMsg;
struct ForumModelPostEntry;

namespace Ui {
class GxsForumThreadWidget;
}

class GxsForumThreadWidget : public GxsMessageFrameWidget
{
	Q_OBJECT

	typedef void (GxsForumThreadWidget::*MsgMethod)(const RsGxsForumMsg&) ;

	Q_PROPERTY(QColor textColorRead READ textColorRead WRITE setTextColorRead)
	Q_PROPERTY(QColor textColorUnread READ textColorUnread WRITE setTextColorUnread)
	Q_PROPERTY(QColor textColorUnreadChildren READ textColorUnreadChildren WRITE setTextColorUnreadChildren)
	Q_PROPERTY(QColor textColorNotSubscribed READ textColorNotSubscribed WRITE setTextColorNotSubscribed)
	Q_PROPERTY(QColor textColorMissing READ textColorMissing WRITE setTextColorMissing)
	Q_PROPERTY(QColor textColorPinned READ textColorPinned WRITE setTextColorPinned)

	Q_PROPERTY(QColor backgroundColorPinned READ backgroundColorPinned WRITE setBackgroundColorPinned)
	Q_PROPERTY(QColor backgroundColorFiltered READ backgroundColorFiltered WRITE setBackgroundColorFiltered)

public:
	explicit GxsForumThreadWidget(const RsGxsGroupId &forumId, QWidget *parent = NULL);
	~GxsForumThreadWidget();

	QColor textColorRead() const { return mTextColorRead; }
	QColor textColorUnread() const { return mTextColorUnread; }
	QColor textColorUnreadChildren() const { return mTextColorUnreadChildren; }
	QColor textColorNotSubscribed() const { return mTextColorNotSubscribed; }
	QColor textColorMissing() const { return mTextColorMissing; }
	QColor textColorPinned() const { return mTextColorPinned; }

	QColor backgroundColorPinned() const { return mBackgroundColorPinned; }
	QColor backgroundColorFiltered() const { return mBackgroundColorFiltered; }

	void setTextColorRead          (QColor color) ;
	void setTextColorUnread        (QColor color) ;
	void setTextColorUnreadChildren(QColor color) ;
	void setTextColorNotSubscribed (QColor color) ;
	void setTextColorMissing       (QColor color) ;
	void setTextColorPinned        (QColor color) ;

	void setBackgroundColorPinned   (QColor color);
	void setBackgroundColorFiltered (QColor color);

	/* GxsMessageFrameWidget */
	virtual void groupIdChanged();
	virtual QString groupName(bool withUnreadCount);
	virtual QIcon groupIcon();
	virtual bool navigate(const RsGxsMessageId& msgId);

	unsigned int newCount() { return mNewCount; }
	unsigned int unreadCount() { return mUnreadCount; }

	QTreeWidgetItem *generateMissingItem(const RsGxsMessageId &msgId);

    virtual void blank();

protected:
	//bool eventFilter(QObject *obj, QEvent *ev);
	//void changeEvent(QEvent *e);

	/* RsGxsUpdateBroadcastWidget */
	virtual void updateDisplay(bool complete);

	/* GxsMessageFrameWidget */
    virtual void setAllMessagesReadDo(bool read);
    
	void setMessageLoadingError(const QString& error);
private slots:
	/** Create the context popup menu and it's submenus */
	void threadListCustomPopupMenu(QPoint point);
	void headerContextMenuRequested(const QPoint& pos);
    void showForumInfo();

	void changedSelection(const QModelIndex &, const QModelIndex &);
	void changedThread(QModelIndex index);
	void changedVersion();
	void clickedThread (QModelIndex index);
	void postForumLoading();

	void reply_with_private_message();
	void replytoforummessage();
	void editforummessage();

    void toggleThreadedView(bool);
    void toggleFlatView(bool);
    void toggleLstPostInThreadView(bool);

    void replyMessageData(const RsGxsForumMsg &msg);
	void editForumMessageData(const RsGxsForumMsg &msg);
	void replyForumMessageData(const RsGxsForumMsg &msg);
	void showAuthorInPeople(const RsGxsForumMsg& msg);

    // This method is used to perform an asynchroneous action on the message data. Any of the methods above can be used as parameter.
	void async_msg_action(const MsgMethod& method);

	void markMsgAsRead();
	void markMsgAsReadChildren();
	void markMsgAsUnread();
	void markMsgAsUnreadChildren();

	void copyMessageLink();
	void showInPeopleTab();

	/* handle splitter */
	void togglethreadview();

	void subscribeGroup(bool subscribe);
	void createthread();
	void togglePinUpPost();
	void createmessage();

	void previousMessage();
	void nextMessage();
	void nextUnreadMessage();
	void downloadAllFiles();

    void changedViewBox(int);
	void flagperson();

	void filterColumnChanged(int column);
	void filterItems(const QString &text);

#if QT_VERSION >= QT_VERSION_CHECK(5, 13, 0)
	void expandSubtree();
#endif
	void changeHeaderColumnVisibility(bool visibility);
	void showBannedText(bool display);
private:
	void insertMessageData(const RsGxsForumMsg &msg);
	bool getCurrentPost(ForumModelPostEntry& fmpe) const ;
	QModelIndex getCurrentIndex() const;

	void insertMessage();
	void insertGroupData();

	void recursRestoreExpandedItems(const QModelIndex& index, const QList<RsGxsMessageId>& expanded_items);
	void recursSaveExpandedItems(const QModelIndex& index, QList<RsGxsMessageId>& expanded_items) const;
	void saveExpandedItems(QList<RsGxsMessageId>& expanded_items) const;

	int getSelectedMsgCount(QList<QTreeWidgetItem*> *pRows, QList<QTreeWidgetItem*> *pRowsRead, QList<QTreeWidgetItem*> *pRowsUnread);
	void setMsgReadStatus(QList<QTreeWidgetItem*> &rows, bool read);
	void markMsgAsReadUnread(bool read, bool children, bool forum, RsGxsMessageId msgId = RsGxsMessageId());
	void calculateUnreadCount();

	void togglethreadview_internal();

	//bool filterItem(QTreeWidgetItem *item, const QString &text, int filterColumn);

	void processSettings(bool bLoad);

	void updateGroupData();
    static void loadAuthorIdCallback(GxsIdDetailsType type, const RsIdentityDetails &details, QObject *object, const QVariant &/*data*/);

	void updateMessageData(const RsGxsMessageId& msgId);
	void updateForumDescription(bool success);

	void handleEvent_main_thread(std::shared_ptr<const RsEvent> event);

private:
	void setForumDescriptionLoading();
	void clearForumDescription();
    void blankPost();

	RsGxsGroupId mLastForumID;
	RsGxsMessageId mThreadId;
	RsGxsMessageId mOrigThreadId;
    RsGxsForumGroup mForumGroup;
    //bool mUpdating;
	bool mInProcessSettings;
	bool mInMsgAsReadUnread;
	int mLastViewType;
	RSTreeWidgetItemCompareRole *mThreadCompareRole;
	GxsForumsFillThread *mFillThread;
	unsigned int mUnreadCount;
	unsigned int mNewCount;
	bool mDisplayBannedText;

	/* Color definitions (for standard see default.qss) */
	QColor mTextColorRead;
	QColor mTextColorUnread;
	QColor mTextColorUnreadChildren;
	QColor mTextColorNotSubscribed;
	QColor mTextColorMissing;
	QColor mTextColorPinned;

	QColor mBackgroundColorPinned;
	QColor mBackgroundColorFiltered;

	std::map<RsGxsGroupId,RsGxsMessageId> mLastSelectedPosts;
	RsGxsMessageId mNavigatePendingMsgId;
	QList<RsGxsMessageId> mIgnoredMsgId;

    RsGxsForumModel *mThreadModel;
    QSortFilterProxyModel *mThreadProxyModel;
    QList<RsGxsMessageId> mSavedExpandedMessages;

    FontSizeHandler mFontSizeHandler;

    Ui::GxsForumThreadWidget *ui;
    RsEventsHandlerId_t mEventHandlerId;
};

#endif // GXSFORUMTHREADWIDGET_H
