/**********************************************************
        执行体头文件KrlExecutor.h
***********************************************************
                彭东
**********************************************************/
#ifndef _KRLEXECUTORHEAD
#define _KRLEXECUTORHEAD

#include "KrlExecutorManage.h"

#define EXECUTOR_INIT_STATUS (0)
#define EXECUTOR_NEW_STATUS (2)
#define EXECUTOR_RUN_STATUS (4)
#define EXECUTOR_SLEEP_STATUS (8)
#define EXECUTOR_BLOCK_STATUS (16)
#define EXECUTOR_WAIT_STATUS (32)
#define EXECUTOR_DEAD_STATUS (64)
#define EXECUTOR_CACHE_STATUS (128)

typedef struct EXAFFILIATION
{
    UInt CPUID;
    UInt MNodeID;
    ExecutorBox* ExecutorBoxPtr;
    ExecutorNode* ExecutorNodePtr;
    //User
    //Transfer
    //Group
}ExAffiliation;

typedef struct THREADHEAD
{
     UInt ThreadNR;
     List ThreadLists;
}ThreadHead;

typedef struct THREADBOX
{
    ELock Lock;
	U64 Status;
	U64 Flags;
    UInt ThreadSumNR;
    ThreadHead NewHead;
    ThreadHead RunHead;
    ThreadHead SleepHead;
    ThreadHead BlockHead;
    ThreadHead WaitHead;
    ThreadHead DeadHead;
    ThreadHead CacheHead;
}ThreadBox;

typedef struct EXECUTOR
{
    List Lists;
    ELock Lock;
	U64 Status;
	U64 Flags;
    UInt Type;
	UInt RunStatus;
    ExAffiliation Affiliation;
    ThreadBox ExThreadBox;
    VMS ExVMS;   
    void* Res;
    void* Priv;
    void* Ext;
}Executor;

#endif