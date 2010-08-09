#ifndef RS_P3_FORUMS_INTERFACE_H
#define RS_P3_FORUMS_INTERFACE_H

/*
 * libretroshare/src/services: p3forums.h
 *
 * RetroShare C++ Interface.
 *
 * Copyright 2008 by Robert Fernie.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License Version 2 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA.
 *
 * Please report all bugs and problems to "retroshare@lunamutt.com".
 *
 */

#include "retroshare/rsforums.h"
#include "services/p3distrib.h"
#include "serialiser/rsforumitems.h"



class p3Forums: public p3GroupDistrib, public RsForums 
{
	public:

	p3Forums(uint16_t type, CacheStrapper *cs, CacheTransfer *cft,
                std::string srcdir, std::string storedir, std::string forumdir);
virtual ~p3Forums();

void	loadDummyData();

/****************************************/
/********* rsForums Interface ***********/

virtual bool forumsChanged(std::list<std::string> &forumIds);

virtual std::string createForum(std::wstring forumName, std::wstring forumDesc, uint32_t forumFlags);

virtual bool getForumInfo(std::string fId, ForumInfo &fi);
virtual bool getForumList(std::list<ForumInfo> &forumList);
virtual bool getForumThreadList(std::string fId, std::list<ThreadInfoSummary> &msgs);
virtual bool getForumThreadMsgList(std::string fId, std::string tId, std::list<ThreadInfoSummary> &msgs);
virtual bool getForumMessage(std::string fId, std::string mId, ForumMsgInfo &msg);
virtual	bool ForumMessageSend(ForumMsgInfo &info);
virtual bool setMessageStatus(const std::string& fId, const std::string& mId, const uint32_t status, const uint32_t statusMask);
virtual bool getMessageStatus(const std::string& fId, const std::string& mId, uint32_t& status);

virtual bool forumSubscribe(std::string fId, bool subscribe);

/***************************************************************************************/
/****************** Event Feedback (Overloaded form p3distrib) *************************/
/***************************************************************************************/

virtual void locked_notifyGroupChanged(GroupInfo &grp, uint32_t flags);
virtual bool locked_eventDuplicateMsg(GroupInfo *, RsDistribMsg *, std::string);
virtual bool locked_eventNewMsg(GroupInfo *, RsDistribMsg *, std::string);



/****************************************/
/********* Overloaded Functions *********/

//virtual RsSerialiser *setupSerialiser();
//virtual pqistreamer *createStreamer(BinInterface *bio, std::string src, uint32_t bioflags);
virtual RsSerialType *createSerialiser();

virtual bool    locked_checkDistribMsg(RsDistribMsg *msg);
virtual RsDistribGrp *locked_createPublicDistribGrp(GroupInfo &info);
virtual RsDistribGrp *locked_createPrivateDistribGrp(GroupInfo &info);
virtual bool childLoadList(std::list<RsItem *>& );
virtual std::list<RsItem *> childSaveList();


/****************************************/

std::string createForumMsg(std::string fId, std::string pId,
                     std::wstring title, std::wstring msg, bool signIt);

	private:

std::string mForumsDir;
std::list<RsItem *> mSaveList; // store save data

std::list<RsForumReadStatus *> mReadStatus;

};


#endif
