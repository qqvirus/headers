typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0008 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0010 */

typedef struct _DISPATCHER_HEADER
{
  union
  {
    /* 0x0000 */ volatile long Lock;
    /* 0x0000 */ long LockNV;
    struct
    {
      /* 0x0000 */ unsigned char Type;
      /* 0x0001 */ unsigned char Signalling;
      /* 0x0002 */ unsigned char Size;
      /* 0x0003 */ unsigned char Reserved1;
    }; /* size: 0x0004 */
    struct
    {
      /* 0x0000 */ unsigned char TimerType;
      union
      {
        /* 0x0001 */ unsigned char TimerControlFlags;
        struct
        {
          struct /* bitfield */
          {
            /* 0x0001 */ unsigned char Absolute : 1; /* bit position: 0 */
            /* 0x0001 */ unsigned char Wake : 1; /* bit position: 1 */
            /* 0x0001 */ unsigned char EncodedTolerableDelay : 6; /* bit position: 2 */
          }; /* bitfield */
          /* 0x0002 */ unsigned char Hand;
          union
          {
            /* 0x0003 */ unsigned char TimerMiscFlags;
            struct /* bitfield */
            {
              /* 0x0003 */ unsigned char Index : 6; /* bit position: 0 */
              /* 0x0003 */ unsigned char Inserted : 1; /* bit position: 6 */
              /* 0x0003 */ volatile unsigned char Expired : 1; /* bit position: 7 */
            }; /* bitfield */
          }; /* size: 0x0001 */
        }; /* size: 0x0003 */
      }; /* size: 0x0003 */
    }; /* size: 0x0004 */
    struct
    {
      /* 0x0000 */ unsigned char Timer2Type;
      union
      {
        /* 0x0001 */ unsigned char Timer2Flags;
        struct
        {
          struct /* bitfield */
          {
            /* 0x0001 */ unsigned char Timer2Inserted : 1; /* bit position: 0 */
            /* 0x0001 */ unsigned char Timer2Expiring : 1; /* bit position: 1 */
            /* 0x0001 */ unsigned char Timer2CancelPending : 1; /* bit position: 2 */
            /* 0x0001 */ unsigned char Timer2SetPending : 1; /* bit position: 3 */
            /* 0x0001 */ unsigned char Timer2Running : 1; /* bit position: 4 */
            /* 0x0001 */ unsigned char Timer2Disabled : 1; /* bit position: 5 */
            /* 0x0001 */ unsigned char Timer2ReservedFlags : 2; /* bit position: 6 */
          }; /* bitfield */
          /* 0x0002 */ unsigned char Timer2Reserved1;
          /* 0x0003 */ unsigned char Timer2Reserved2;
        }; /* size: 0x0003 */
      }; /* size: 0x0003 */
    }; /* size: 0x0004 */
    struct
    {
      /* 0x0000 */ unsigned char QueueType;
      union
      {
        /* 0x0001 */ unsigned char QueueControlFlags;
        struct
        {
          struct /* bitfield */
          {
            /* 0x0001 */ unsigned char Abandoned : 1; /* bit position: 0 */
            /* 0x0001 */ unsigned char DisableIncrement : 1; /* bit position: 1 */
            /* 0x0001 */ unsigned char QueueReservedControlFlags : 6; /* bit position: 2 */
          }; /* bitfield */
          /* 0x0002 */ unsigned char QueueSize;
          /* 0x0003 */ unsigned char QueueReserved;
        }; /* size: 0x0003 */
      }; /* size: 0x0003 */
    }; /* size: 0x0004 */
    struct
    {
      /* 0x0000 */ unsigned char ThreadType;
      /* 0x0001 */ unsigned char ThreadReserved;
      union
      {
        /* 0x0002 */ unsigned char ThreadControlFlags;
        struct
        {
          struct /* bitfield */
          {
            /* 0x0002 */ unsigned char CycleProfiling : 1; /* bit position: 0 */
            /* 0x0002 */ unsigned char CounterProfiling : 1; /* bit position: 1 */
            /* 0x0002 */ unsigned char GroupScheduling : 1; /* bit position: 2 */
            /* 0x0002 */ unsigned char AffinitySet : 1; /* bit position: 3 */
            /* 0x0002 */ unsigned char Tagged : 1; /* bit position: 4 */
            /* 0x0002 */ unsigned char EnergyProfiling : 1; /* bit position: 5 */
            /* 0x0002 */ unsigned char ThreadReservedControlFlags : 2; /* bit position: 6 */
          }; /* bitfield */
          union
          {
            /* 0x0003 */ unsigned char DebugActive;
            struct /* bitfield */
            {
              /* 0x0003 */ unsigned char ActiveDR7 : 1; /* bit position: 0 */
              /* 0x0003 */ unsigned char Instrumented : 1; /* bit position: 1 */
              /* 0x0003 */ unsigned char Minimal : 1; /* bit position: 2 */
              /* 0x0003 */ unsigned char Reserved4 : 3; /* bit position: 3 */
              /* 0x0003 */ unsigned char UmsScheduled : 1; /* bit position: 6 */
              /* 0x0003 */ unsigned char UmsPrimary : 1; /* bit position: 7 */
            }; /* bitfield */
          }; /* size: 0x0001 */
        }; /* size: 0x0002 */
      }; /* size: 0x0002 */
    }; /* size: 0x0004 */
    struct
    {
      /* 0x0000 */ unsigned char MutantType;
      /* 0x0001 */ unsigned char MutantSize;
      /* 0x0002 */ unsigned char DpcActive;
      /* 0x0003 */ unsigned char MutantReserved;
    }; /* size: 0x0004 */
  }; /* size: 0x0004 */
  /* 0x0004 */ long SignalState;
  /* 0x0008 */ struct _LIST_ENTRY WaitListHead;
} DISPATCHER_HEADER, *PDISPATCHER_HEADER; /* size: 0x0018 */

typedef struct _KAFFINITY_EX
{
  /* 0x0000 */ unsigned short Count;
  /* 0x0002 */ unsigned short Size;
  /* 0x0004 */ unsigned long Reserved;
  /* 0x0008 */ unsigned __int64 Bitmap[20];
} KAFFINITY_EX, *PKAFFINITY_EX; /* size: 0x00a8 */

typedef struct _SINGLE_LIST_ENTRY
{
  /* 0x0000 */ struct _SINGLE_LIST_ENTRY* Next;
} SINGLE_LIST_ENTRY, *PSINGLE_LIST_ENTRY; /* size: 0x0008 */

typedef union _KEXECUTE_OPTIONS
{
  union
  {
    struct /* bitfield */
    {
      /* 0x0000 */ unsigned char ExecuteDisable : 1; /* bit position: 0 */
      /* 0x0000 */ unsigned char ExecuteEnable : 1; /* bit position: 1 */
      /* 0x0000 */ unsigned char DisableThunkEmulation : 1; /* bit position: 2 */
      /* 0x0000 */ unsigned char Permanent : 1; /* bit position: 3 */
      /* 0x0000 */ unsigned char ExecuteDispatchEnable : 1; /* bit position: 4 */
      /* 0x0000 */ unsigned char ImageDispatchEnable : 1; /* bit position: 5 */
      /* 0x0000 */ unsigned char DisableExceptionChainValidation : 1; /* bit position: 6 */
      /* 0x0000 */ unsigned char Spare : 1; /* bit position: 7 */
    }; /* bitfield */
    /* 0x0000 */ volatile unsigned char ExecuteOptions;
    /* 0x0000 */ unsigned char ExecuteOptionsNV;
  }; /* size: 0x0001 */
} KEXECUTE_OPTIONS, *PKEXECUTE_OPTIONS; /* size: 0x0001 */

typedef union _KSTACK_COUNT
{
  union
  {
    /* 0x0000 */ long Value;
    struct /* bitfield */
    {
      /* 0x0000 */ unsigned long State : 3; /* bit position: 0 */
      /* 0x0000 */ unsigned long StackCount : 29; /* bit position: 3 */
    }; /* bitfield */
  }; /* size: 0x0004 */
} KSTACK_COUNT, *PKSTACK_COUNT; /* size: 0x0004 */

typedef union _KGDTENTRY64
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned short LimitLow;
      /* 0x0002 */ unsigned short BaseLow;
      union
      {
        struct // _TAG_UNNAMED_52
        {
          /* 0x0004 */ unsigned char BaseMiddle;
          /* 0x0005 */ unsigned char Flags1;
          /* 0x0006 */ unsigned char Flags2;
          /* 0x0007 */ unsigned char BaseHigh;
        } /* size: 0x0004 */ Bytes;
        struct
        {
          struct // _TAG_UNNAMED_53
          {
            struct /* bitfield */
            {
              /* 0x0004 */ unsigned long BaseMiddle : 8; /* bit position: 0 */
              /* 0x0004 */ unsigned long Type : 5; /* bit position: 8 */
              /* 0x0004 */ unsigned long Dpl : 2; /* bit position: 13 */
              /* 0x0004 */ unsigned long Present : 1; /* bit position: 15 */
              /* 0x0004 */ unsigned long LimitHigh : 4; /* bit position: 16 */
              /* 0x0004 */ unsigned long System : 1; /* bit position: 20 */
              /* 0x0004 */ unsigned long LongMode : 1; /* bit position: 21 */
              /* 0x0004 */ unsigned long DefaultBig : 1; /* bit position: 22 */
              /* 0x0004 */ unsigned long Granularity : 1; /* bit position: 23 */
              /* 0x0004 */ unsigned long BaseHigh : 8; /* bit position: 24 */
            }; /* bitfield */
          } /* size: 0x0004 */ Bits;
          /* 0x0008 */ unsigned long BaseUpper;
          /* 0x000c */ unsigned long MustBeZero;
        }; /* size: 0x000c */
      }; /* size: 0x000c */
    }; /* size: 0x0010 */
    struct
    {
      /* 0x0000 */ __int64 DataLow;
      /* 0x0008 */ __int64 DataHigh;
    }; /* size: 0x0010 */
  }; /* size: 0x0010 */
} KGDTENTRY64, *PKGDTENTRY64; /* size: 0x0010 */

typedef struct _KEVENT
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
} KEVENT, *PKEVENT; /* size: 0x0018 */

typedef struct _FAST_MUTEX
{
  /* 0x0000 */ long Count;
  /* 0x0008 */ void* Owner;
  /* 0x0010 */ unsigned long Contention;
  /* 0x0018 */ struct _KEVENT Event;
  /* 0x0030 */ unsigned long OldIrql;
  /* 0x0034 */ long __PADDING__[1];
} FAST_MUTEX, *PFAST_MUTEX; /* size: 0x0038 */

typedef struct _KPROCESS
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
  /* 0x0018 */ struct _LIST_ENTRY ProfileListHead;
  /* 0x0028 */ unsigned __int64 DirectoryTableBase;
  /* 0x0030 */ struct _LIST_ENTRY ThreadListHead;
  /* 0x0040 */ unsigned long ProcessLock;
  /* 0x0044 */ unsigned long Spare0;
  /* 0x0048 */ unsigned __int64 DeepFreezeStartTime;
  /* 0x0050 */ struct _KAFFINITY_EX Affinity;
  /* 0x00f8 */ struct _LIST_ENTRY ReadyListHead;
  /* 0x0108 */ struct _SINGLE_LIST_ENTRY SwapListEntry;
  /* 0x0110 */ volatile struct _KAFFINITY_EX ActiveProcessors;
  union
  {
    struct /* bitfield */
    {
      /* 0x01b8 */ long AutoAlignment : 1; /* bit position: 0 */
      /* 0x01b8 */ long DisableBoost : 1; /* bit position: 1 */
      /* 0x01b8 */ long DisableQuantum : 1; /* bit position: 2 */
      /* 0x01b8 */ unsigned long DeepFreeze : 1; /* bit position: 3 */
      /* 0x01b8 */ unsigned long TimerVirtualization : 1; /* bit position: 4 */
      /* 0x01b8 */ unsigned long CheckStackExtents : 1; /* bit position: 5 */
      /* 0x01b8 */ unsigned long SpareFlags0 : 2; /* bit position: 6 */
      /* 0x01b8 */ unsigned long ActiveGroupsMask : 20; /* bit position: 8 */
      /* 0x01b8 */ long ReservedFlags : 4; /* bit position: 28 */
    }; /* bitfield */
    /* 0x01b8 */ volatile long ProcessFlags;
  }; /* size: 0x0004 */
  /* 0x01bc */ char BasePriority;
  /* 0x01bd */ char QuantumReset;
  /* 0x01be */ unsigned char Visited;
  /* 0x01bf */ union _KEXECUTE_OPTIONS Flags;
  /* 0x01c0 */ unsigned long ThreadSeed[20];
  /* 0x0210 */ unsigned short IdealNode[20];
  /* 0x0238 */ unsigned short IdealGlobalNode;
  /* 0x023a */ unsigned short Spare1;
  /* 0x023c */ volatile union _KSTACK_COUNT StackCount;
  /* 0x0240 */ struct _LIST_ENTRY ProcessListEntry;
  /* 0x0250 */ unsigned __int64 CycleTime;
  /* 0x0258 */ unsigned __int64 ContextSwitches;
  /* 0x0260 */ struct _KSCHEDULING_GROUP* SchedulingGroup;
  /* 0x0268 */ unsigned long FreezeCount;
  /* 0x026c */ unsigned long KernelTime;
  /* 0x0270 */ unsigned long UserTime;
  /* 0x0274 */ unsigned short LdtFreeSelectorHint;
  /* 0x0276 */ unsigned short LdtTableLength;
  /* 0x0278 */ union _KGDTENTRY64 LdtSystemDescriptor;
  /* 0x0288 */ void* LdtBaseAddress;
  /* 0x0290 */ struct _FAST_MUTEX LdtProcessLock;
  /* 0x02c8 */ void* InstrumentationCallback;
  /* 0x02d0 */ unsigned __int64 SecurePid;
} KPROCESS, *PKPROCESS; /* size: 0x02d8 */

typedef struct _EX_PUSH_LOCK
{
  union
  {
    struct /* bitfield */
    {
      /* 0x0000 */ unsigned __int64 Locked : 1; /* bit position: 0 */
      /* 0x0000 */ unsigned __int64 Waiting : 1; /* bit position: 1 */
      /* 0x0000 */ unsigned __int64 Waking : 1; /* bit position: 2 */
      /* 0x0000 */ unsigned __int64 MultipleShared : 1; /* bit position: 3 */
      /* 0x0000 */ unsigned __int64 Shared : 60; /* bit position: 4 */
    }; /* bitfield */
    /* 0x0000 */ unsigned __int64 Value;
    /* 0x0000 */ void* Ptr;
  }; /* size: 0x0008 */
} EX_PUSH_LOCK, *PEX_PUSH_LOCK; /* size: 0x0008 */

typedef struct _EX_RUNDOWN_REF
{
  union
  {
    /* 0x0000 */ unsigned __int64 Count;
    /* 0x0000 */ void* Ptr;
  }; /* size: 0x0008 */
} EX_RUNDOWN_REF, *PEX_RUNDOWN_REF; /* size: 0x0008 */

typedef union _LARGE_INTEGER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ long HighPart;
    }; /* size: 0x0008 */
    struct // _TAG_UNNAMED_1
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ long HighPart;
    } /* size: 0x0008 */ u;
    /* 0x0000 */ __int64 QuadPart;
  }; /* size: 0x0008 */
} LARGE_INTEGER, *PLARGE_INTEGER; /* size: 0x0008 */

typedef struct _EX_FAST_REF
{
  union
  {
    /* 0x0000 */ void* Object;
    /* 0x0000 */ unsigned __int64 RefCnt : 4; /* bit position: 0 */
    /* 0x0000 */ unsigned __int64 Value;
  }; /* size: 0x0008 */
} EX_FAST_REF, *PEX_FAST_REF; /* size: 0x0008 */

typedef struct _RTL_AVL_TREE
{
  /* 0x0000 */ struct _RTL_BALANCED_NODE* Root;
} RTL_AVL_TREE, *PRTL_AVL_TREE; /* size: 0x0008 */

typedef struct _SE_AUDIT_PROCESS_CREATION_INFO
{
  /* 0x0000 */ struct _OBJECT_NAME_INFORMATION* ImageFileName;
} SE_AUDIT_PROCESS_CREATION_INFO, *PSE_AUDIT_PROCESS_CREATION_INFO; /* size: 0x0008 */

typedef struct _MMSUPPORT_FLAGS
{
  struct /* bitfield */
  {
    /* 0x0000 */ unsigned char WorkingSetType : 3; /* bit position: 0 */
    /* 0x0000 */ unsigned char Reserved0 : 3; /* bit position: 3 */
    /* 0x0000 */ unsigned char MaximumWorkingSetHard : 1; /* bit position: 6 */
    /* 0x0000 */ unsigned char MinimumWorkingSetHard : 1; /* bit position: 7 */
  }; /* bitfield */
  struct /* bitfield */
  {
    /* 0x0001 */ unsigned char SessionMaster : 1; /* bit position: 0 */
    /* 0x0001 */ unsigned char TrimmerState : 2; /* bit position: 1 */
    /* 0x0001 */ unsigned char Reserved : 1; /* bit position: 3 */
    /* 0x0001 */ unsigned char PageStealers : 4; /* bit position: 4 */
  }; /* bitfield */
  /* 0x0002 */ unsigned char MemoryPriority;
  struct /* bitfield */
  {
    /* 0x0003 */ unsigned char WsleDeleted : 1; /* bit position: 0 */
    /* 0x0003 */ unsigned char VmExiting : 1; /* bit position: 1 */
    /* 0x0003 */ unsigned char ExpansionFailed : 1; /* bit position: 2 */
    /* 0x0003 */ unsigned char SvmEnabled : 1; /* bit position: 3 */
    /* 0x0003 */ unsigned char ForceAge : 1; /* bit position: 4 */
    /* 0x0003 */ unsigned char NewMaximum : 1; /* bit position: 5 */
    /* 0x0003 */ unsigned char CommitReleaseState : 2; /* bit position: 6 */
  }; /* bitfield */
} MMSUPPORT_FLAGS, *PMMSUPPORT_FLAGS; /* size: 0x0004 */

typedef struct _MMSUPPORT
{
  /* 0x0000 */ volatile long WorkingSetLock;
  /* 0x0008 */ struct _KGATE* ExitOutswapGate;
  /* 0x0010 */ void* AccessLog;
  /* 0x0018 */ struct _LIST_ENTRY WorkingSetExpansionLinks;
  /* 0x0028 */ unsigned __int64 AgeDistribution[7];
  /* 0x0060 */ unsigned __int64 MinimumWorkingSetSize;
  /* 0x0068 */ unsigned __int64 WorkingSetLeafSize;
  /* 0x0070 */ unsigned __int64 WorkingSetLeafPrivateSize;
  /* 0x0078 */ unsigned __int64 WorkingSetSize;
  /* 0x0080 */ unsigned __int64 WorkingSetPrivateSize;
  /* 0x0088 */ unsigned __int64 MaximumWorkingSetSize;
  /* 0x0090 */ unsigned __int64 ChargedWslePages;
  /* 0x0098 */ unsigned __int64 ActualWslePages;
  /* 0x00a0 */ unsigned __int64 WorkingSetSizeOverhead;
  /* 0x00a8 */ unsigned __int64 PeakWorkingSetSize;
  /* 0x00b0 */ unsigned long HardFaultCount;
  /* 0x00b4 */ unsigned short PartitionId;
  /* 0x00b6 */ unsigned short Pad0;
  /* 0x00b8 */ struct _MMWSL* VmWorkingSetList;
  /* 0x00c0 */ unsigned short NextPageColor;
  /* 0x00c2 */ unsigned short LastTrimStamp;
  /* 0x00c4 */ unsigned long PageFaultCount;
  /* 0x00c8 */ unsigned __int64 TrimmedPageCount;
  /* 0x00d0 */ unsigned __int64 Reserved0;
  /* 0x00d8 */ struct _MMSUPPORT_FLAGS Flags;
  /* 0x00e0 */ unsigned __int64 ReleasedCommitDebt;
  /* 0x00e8 */ void* WsSwapSupport;
  /* 0x00f0 */ void* CommitReAcquireFailSupport;
} MMSUPPORT, *PMMSUPPORT; /* size: 0x00f8 */

typedef struct _ALPC_PROCESS_CONTEXT
{
  /* 0x0000 */ struct _EX_PUSH_LOCK Lock;
  /* 0x0008 */ struct _LIST_ENTRY ViewListHead;
  /* 0x0018 */ volatile unsigned __int64 PagedPoolQuotaCache;
} ALPC_PROCESS_CONTEXT, *PALPC_PROCESS_CONTEXT; /* size: 0x0020 */

typedef struct _PS_PROTECTION
{
  union
  {
    /* 0x0000 */ unsigned char Level;
    struct /* bitfield */
    {
      /* 0x0000 */ unsigned char Type : 3; /* bit position: 0 */
      /* 0x0000 */ unsigned char Audit : 1; /* bit position: 3 */
      /* 0x0000 */ unsigned char Signer : 4; /* bit position: 4 */
    }; /* bitfield */
  }; /* size: 0x0001 */
} PS_PROTECTION, *PPS_PROTECTION; /* size: 0x0001 */

typedef struct _EPROCESS
{
  /* 0x0000 */ struct _KPROCESS Pcb;
  /* 0x02d8 */ struct _EX_PUSH_LOCK ProcessLock;
  /* 0x02e0 */ struct _EX_RUNDOWN_REF RundownProtect;
  /* 0x02e8 */ void* UniqueProcessId;
  /* 0x02f0 */ struct _LIST_ENTRY ActiveProcessLinks;
  union
  {
    /* 0x0300 */ unsigned long Flags2;
    struct /* bitfield */
    {
      /* 0x0300 */ unsigned long JobNotReallyActive : 1; /* bit position: 0 */
      /* 0x0300 */ unsigned long AccountingFolded : 1; /* bit position: 1 */
      /* 0x0300 */ unsigned long NewProcessReported : 1; /* bit position: 2 */
      /* 0x0300 */ unsigned long ExitProcessReported : 1; /* bit position: 3 */
      /* 0x0300 */ unsigned long ReportCommitChanges : 1; /* bit position: 4 */
      /* 0x0300 */ unsigned long LastReportMemory : 1; /* bit position: 5 */
      /* 0x0300 */ unsigned long ForceWakeCharge : 1; /* bit position: 6 */
      /* 0x0300 */ unsigned long CrossSessionCreate : 1; /* bit position: 7 */
      /* 0x0300 */ unsigned long NeedsHandleRundown : 1; /* bit position: 8 */
      /* 0x0300 */ unsigned long RefTraceEnabled : 1; /* bit position: 9 */
      /* 0x0300 */ unsigned long DisableDynamicCode : 1; /* bit position: 10 */
      /* 0x0300 */ unsigned long EmptyJobEvaluated : 1; /* bit position: 11 */
      /* 0x0300 */ unsigned long DefaultPagePriority : 3; /* bit position: 12 */
      /* 0x0300 */ unsigned long PrimaryTokenFrozen : 1; /* bit position: 15 */
      /* 0x0300 */ unsigned long ProcessVerifierTarget : 1; /* bit position: 16 */
      /* 0x0300 */ unsigned long StackRandomizationDisabled : 1; /* bit position: 17 */
      /* 0x0300 */ unsigned long AffinityPermanent : 1; /* bit position: 18 */
      /* 0x0300 */ unsigned long AffinityUpdateEnable : 1; /* bit position: 19 */
      /* 0x0300 */ unsigned long PropagateNode : 1; /* bit position: 20 */
      /* 0x0300 */ unsigned long ExplicitAffinity : 1; /* bit position: 21 */
      /* 0x0300 */ unsigned long ProcessExecutionState : 2; /* bit position: 22 */
      /* 0x0300 */ unsigned long DisallowStrippedImages : 1; /* bit position: 24 */
      /* 0x0300 */ unsigned long HighEntropyASLREnabled : 1; /* bit position: 25 */
      /* 0x0300 */ unsigned long ExtensionPointDisable : 1; /* bit position: 26 */
      /* 0x0300 */ unsigned long ForceRelocateImages : 1; /* bit position: 27 */
      /* 0x0300 */ unsigned long ProcessStateChangeRequest : 2; /* bit position: 28 */
      /* 0x0300 */ unsigned long ProcessStateChangeInProgress : 1; /* bit position: 30 */
      /* 0x0300 */ unsigned long DisallowWin32kSystemCalls : 1; /* bit position: 31 */
    }; /* bitfield */
  }; /* size: 0x0004 */
  union
  {
    /* 0x0304 */ unsigned long Flags;
    struct /* bitfield */
    {
      /* 0x0304 */ unsigned long CreateReported : 1; /* bit position: 0 */
      /* 0x0304 */ unsigned long NoDebugInherit : 1; /* bit position: 1 */
      /* 0x0304 */ unsigned long ProcessExiting : 1; /* bit position: 2 */
      /* 0x0304 */ unsigned long ProcessDelete : 1; /* bit position: 3 */
      /* 0x0304 */ unsigned long ControlFlowGuardEnabled : 1; /* bit position: 4 */
      /* 0x0304 */ unsigned long VmDeleted : 1; /* bit position: 5 */
      /* 0x0304 */ unsigned long OutswapEnabled : 1; /* bit position: 6 */
      /* 0x0304 */ unsigned long Outswapped : 1; /* bit position: 7 */
      /* 0x0304 */ unsigned long FailFastOnCommitFail : 1; /* bit position: 8 */
      /* 0x0304 */ unsigned long Wow64VaSpace4Gb : 1; /* bit position: 9 */
      /* 0x0304 */ unsigned long AddressSpaceInitialized : 2; /* bit position: 10 */
      /* 0x0304 */ unsigned long SetTimerResolution : 1; /* bit position: 12 */
      /* 0x0304 */ unsigned long BreakOnTermination : 1; /* bit position: 13 */
      /* 0x0304 */ unsigned long DeprioritizeViews : 1; /* bit position: 14 */
      /* 0x0304 */ unsigned long WriteWatch : 1; /* bit position: 15 */
      /* 0x0304 */ unsigned long ProcessInSession : 1; /* bit position: 16 */
      /* 0x0304 */ unsigned long OverrideAddressSpace : 1; /* bit position: 17 */
      /* 0x0304 */ unsigned long HasAddressSpace : 1; /* bit position: 18 */
      /* 0x0304 */ unsigned long LaunchPrefetched : 1; /* bit position: 19 */
      /* 0x0304 */ unsigned long Background : 1; /* bit position: 20 */
      /* 0x0304 */ unsigned long VmTopDown : 1; /* bit position: 21 */
      /* 0x0304 */ unsigned long ImageNotifyDone : 1; /* bit position: 22 */
      /* 0x0304 */ unsigned long PdeUpdateNeeded : 1; /* bit position: 23 */
      /* 0x0304 */ unsigned long VdmAllowed : 1; /* bit position: 24 */
      /* 0x0304 */ unsigned long ProcessRundown : 1; /* bit position: 25 */
      /* 0x0304 */ unsigned long ProcessInserted : 1; /* bit position: 26 */
      /* 0x0304 */ unsigned long DefaultIoPriority : 3; /* bit position: 27 */
      /* 0x0304 */ unsigned long ProcessSelfDelete : 1; /* bit position: 30 */
      /* 0x0304 */ unsigned long SetTimerResolutionLink : 1; /* bit position: 31 */
    }; /* bitfield */
  }; /* size: 0x0004 */
  /* 0x0308 */ union _LARGE_INTEGER CreateTime;
  /* 0x0310 */ unsigned __int64 ProcessQuotaUsage[2];
  /* 0x0320 */ unsigned __int64 ProcessQuotaPeak[2];
  /* 0x0330 */ unsigned __int64 PeakVirtualSize;
  /* 0x0338 */ unsigned __int64 VirtualSize;
  /* 0x0340 */ struct _LIST_ENTRY SessionProcessLinks;
  union
  {
    /* 0x0350 */ void* ExceptionPortData;
    /* 0x0350 */ unsigned __int64 ExceptionPortValue;
    /* 0x0350 */ unsigned __int64 ExceptionPortState : 3; /* bit position: 0 */
  }; /* size: 0x0008 */
  /* 0x0358 */ struct _EX_FAST_REF Token;
  /* 0x0360 */ unsigned __int64 WorkingSetPage;
  /* 0x0368 */ struct _EX_PUSH_LOCK AddressCreationLock;
  /* 0x0370 */ struct _EX_PUSH_LOCK PageTableCommitmentLock;
  /* 0x0378 */ struct _ETHREAD* RotateInProgress;
  /* 0x0380 */ struct _ETHREAD* ForkInProgress;
  /* 0x0388 */ struct _EJOB* volatile CommitChargeJob;
  /* 0x0390 */ struct _RTL_AVL_TREE CloneRoot;
  /* 0x0398 */ volatile unsigned __int64 NumberOfPrivatePages;
  /* 0x03a0 */ volatile unsigned __int64 NumberOfLockedPages;
  /* 0x03a8 */ void* Win32Process;
  /* 0x03b0 */ struct _EJOB* volatile Job;
  /* 0x03b8 */ void* SectionObject;
  /* 0x03c0 */ void* SectionBaseAddress;
  /* 0x03c8 */ unsigned long Cookie;
  /* 0x03d0 */ struct _PAGEFAULT_HISTORY* WorkingSetWatch;
  /* 0x03d8 */ void* Win32WindowStation;
  /* 0x03e0 */ void* InheritedFromUniqueProcessId;
  /* 0x03e8 */ void* LdtInformation;
  /* 0x03f0 */ volatile unsigned __int64 OwnerProcessId;
  /* 0x03f8 */ struct _PEB* Peb;
  /* 0x0400 */ void* Session;
  /* 0x0408 */ void* AweInfo;
  /* 0x0410 */ struct _EPROCESS_QUOTA_BLOCK* QuotaBlock;
  /* 0x0418 */ struct _HANDLE_TABLE* ObjectTable;
  /* 0x0420 */ void* DebugPort;
  /* 0x0428 */ struct _EWOW64PROCESS* WoW64Process;
  /* 0x0430 */ void* DeviceMap;
  /* 0x0438 */ void* EtwDataSource;
  /* 0x0440 */ unsigned __int64 PageDirectoryPte;
  /* 0x0448 */ struct _FILE_OBJECT* ImageFilePointer;
  /* 0x0450 */ unsigned char ImageFileName[15];
  /* 0x045f */ unsigned char PriorityClass;
  /* 0x0460 */ void* SecurityPort;
  /* 0x0468 */ struct _SE_AUDIT_PROCESS_CREATION_INFO SeAuditProcessCreationInfo;
  /* 0x0470 */ struct _LIST_ENTRY JobLinks;
  /* 0x0480 */ void* HighestUserAddress;
  /* 0x0488 */ struct _LIST_ENTRY ThreadListHead;
  /* 0x0498 */ volatile unsigned long ActiveThreads;
  /* 0x049c */ unsigned long ImagePathHash;
  /* 0x04a0 */ unsigned long DefaultHardErrorProcessing;
  /* 0x04a4 */ long LastThreadExitStatus;
  /* 0x04a8 */ struct _EX_FAST_REF PrefetchTrace;
  /* 0x04b0 */ void* LockedPagesList;
  /* 0x04b8 */ union _LARGE_INTEGER ReadOperationCount;
  /* 0x04c0 */ union _LARGE_INTEGER WriteOperationCount;
  /* 0x04c8 */ union _LARGE_INTEGER OtherOperationCount;
  /* 0x04d0 */ union _LARGE_INTEGER ReadTransferCount;
  /* 0x04d8 */ union _LARGE_INTEGER WriteTransferCount;
  /* 0x04e0 */ union _LARGE_INTEGER OtherTransferCount;
  /* 0x04e8 */ unsigned __int64 CommitChargeLimit;
  /* 0x04f0 */ volatile unsigned __int64 CommitCharge;
  /* 0x04f8 */ volatile unsigned __int64 CommitChargePeak;
  /* 0x0500 */ struct _MMSUPPORT Vm;
  /* 0x05f8 */ struct _LIST_ENTRY MmProcessLinks;
  /* 0x0608 */ unsigned long ModifiedPageCount;
  /* 0x060c */ long ExitStatus;
  /* 0x0610 */ struct _RTL_AVL_TREE VadRoot;
  /* 0x0618 */ void* VadHint;
  /* 0x0620 */ unsigned __int64 VadCount;
  /* 0x0628 */ volatile unsigned __int64 VadPhysicalPages;
  /* 0x0630 */ unsigned __int64 VadPhysicalPagesLimit;
  /* 0x0638 */ struct _ALPC_PROCESS_CONTEXT AlpcContext;
  /* 0x0658 */ struct _LIST_ENTRY TimerResolutionLink;
  /* 0x0668 */ struct _PO_DIAG_STACK_RECORD* TimerResolutionStackRecord;
  /* 0x0670 */ unsigned long RequestedTimerResolution;
  /* 0x0674 */ unsigned long SmallestTimerResolution;
  /* 0x0678 */ union _LARGE_INTEGER ExitTime;
  /* 0x0680 */ struct _INVERTED_FUNCTION_TABLE* InvertedFunctionTable;
  /* 0x0688 */ struct _EX_PUSH_LOCK InvertedFunctionTableLock;
  /* 0x0690 */ unsigned long ActiveThreadsHighWatermark;
  /* 0x0694 */ unsigned long LargePrivateVadCount;
  /* 0x0698 */ struct _EX_PUSH_LOCK ThreadListLock;
  /* 0x06a0 */ void* WnfContext;
  /* 0x06a8 */ unsigned __int64 Spare0;
  /* 0x06b0 */ unsigned char SignatureLevel;
  /* 0x06b1 */ unsigned char SectionSignatureLevel;
  /* 0x06b2 */ struct _PS_PROTECTION Protection;
  /* 0x06b3 */ unsigned char HangCount;
  union
  {
    /* 0x06b4 */ unsigned long Flags3;
    struct /* bitfield */
    {
      /* 0x06b4 */ unsigned long Minimal : 1; /* bit position: 0 */
      /* 0x06b4 */ unsigned long ReplacingPageRoot : 1; /* bit position: 1 */
      /* 0x06b4 */ unsigned long DisableNonSystemFonts : 1; /* bit position: 2 */
      /* 0x06b4 */ unsigned long AuditNonSystemFontLoading : 1; /* bit position: 3 */
      /* 0x06b4 */ unsigned long Crashed : 1; /* bit position: 4 */
      /* 0x06b4 */ unsigned long JobVadsAreTracked : 1; /* bit position: 5 */
      /* 0x06b4 */ unsigned long VadTrackingDisabled : 1; /* bit position: 6 */
      /* 0x06b4 */ unsigned long AuxiliaryProcess : 1; /* bit position: 7 */
      /* 0x06b4 */ unsigned long SubsystemProcess : 1; /* bit position: 8 */
      /* 0x06b4 */ unsigned long IndirectCpuSets : 1; /* bit position: 9 */
      /* 0x06b4 */ unsigned long InPrivate : 1; /* bit position: 10 */
      /* 0x06b4 */ unsigned long ProhibitRemoteImageMap : 1; /* bit position: 11 */
      /* 0x06b4 */ unsigned long ProhibitLowILImageMap : 1; /* bit position: 12 */
      /* 0x06b4 */ unsigned long SignatureMitigationOptIn : 1; /* bit position: 13 */
    }; /* bitfield */
  }; /* size: 0x0004 */
  /* 0x06b8 */ long DeviceAsid;
  /* 0x06c0 */ void* SvmData;
  /* 0x06c8 */ struct _EX_PUSH_LOCK SvmProcessLock;
  /* 0x06d0 */ unsigned __int64 SvmLock;
  /* 0x06d8 */ struct _LIST_ENTRY SvmProcessDeviceListHead;
  /* 0x06e8 */ unsigned __int64 LastFreezeInterruptTime;
  /* 0x06f0 */ struct _PROCESS_DISK_COUNTERS* DiskCounters;
  /* 0x06f8 */ void* PicoContext;
  /* 0x0700 */ unsigned __int64 TrustletIdentity;
  /* 0x0708 */ unsigned long KeepAliveCounter;
  /* 0x070c */ unsigned long NoWakeKeepAliveCounter;
  /* 0x0710 */ unsigned long HighPriorityFaultsAllowed;
  /* 0x0718 */ struct _PROCESS_ENERGY_VALUES* EnergyValues;
  /* 0x0720 */ void* VmContext;
  /* 0x0728 */ unsigned __int64 SequenceNumber;
  /* 0x0730 */ unsigned __int64 CreateInterruptTime;
  /* 0x0738 */ unsigned __int64 CreateUnbiasedInterruptTime;
  /* 0x0740 */ unsigned __int64 TotalUnbiasedFrozenTime;
  /* 0x0748 */ unsigned __int64 LastAppStateUpdateTime;
  struct /* bitfield */
  {
    /* 0x0750 */ unsigned __int64 LastAppStateUptime : 61; /* bit position: 0 */
    /* 0x0750 */ unsigned __int64 LastAppState : 3; /* bit position: 61 */
  }; /* bitfield */
  /* 0x0758 */ volatile unsigned __int64 SharedCommitCharge;
  /* 0x0760 */ struct _EX_PUSH_LOCK SharedCommitLock;
  /* 0x0768 */ struct _LIST_ENTRY SharedCommitLinks;
  union
  {
    struct
    {
      /* 0x0778 */ unsigned __int64 AllowedCpuSets;
      /* 0x0780 */ unsigned __int64 DefaultCpuSets;
    }; /* size: 0x0010 */
    struct
    {
      /* 0x0778 */ unsigned __int64* AllowedCpuSetsIndirect;
      /* 0x0780 */ unsigned __int64* DefaultCpuSetsIndirect;
    }; /* size: 0x0010 */
  }; /* size: 0x0010 */
} EPROCESS, *PEPROCESS; /* size: 0x0788 */

