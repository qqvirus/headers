typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0004 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0008 */

typedef struct _DISPATCHER_HEADER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned char Type;
      union
      {
        /* 0x0001 */ unsigned char TimerControlFlags;
        struct /* bitfield */
        {
          /* 0x0001 */ unsigned char Absolute : 1; /* bit position: 0 */
          /* 0x0001 */ unsigned char Wake : 1; /* bit position: 1 */
          /* 0x0001 */ unsigned char EncodedTolerableDelay : 6; /* bit position: 2 */
        }; /* bitfield */
        /* 0x0001 */ unsigned char QueueControlFlags;
        struct /* bitfield */
        {
          /* 0x0001 */ unsigned char Abandoned : 1; /* bit position: 0 */
          /* 0x0001 */ unsigned char DisableIncrement : 1; /* bit position: 1 */
        }; /* bitfield */
        /* 0x0001 */ unsigned char Signalling;
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
            /* 0x0001 */ unsigned char Reserved1 : 2; /* bit position: 6 */
          }; /* bitfield */
          union
          {
            /* 0x0002 */ unsigned char ThreadControlFlags;
            struct /* bitfield */
            {
              /* 0x0002 */ unsigned char CycleProfiling : 1; /* bit position: 0 */
              /* 0x0002 */ unsigned char CounterProfiling : 1; /* bit position: 1 */
              /* 0x0002 */ unsigned char GroupScheduling : 1; /* bit position: 2 */
              /* 0x0002 */ unsigned char AffinitySet : 1; /* bit position: 3 */
              /* 0x0002 */ unsigned char Reserved2 : 4; /* bit position: 4 */
            }; /* bitfield */
            /* 0x0002 */ unsigned char Hand;
            /* 0x0002 */ unsigned char Reserved3;
            struct
            {
              /* 0x0002 */ unsigned char Size;
              union
              {
                /* 0x0003 */ unsigned char TimerMiscFlags;
                struct /* bitfield */
                {
                  /* 0x0003 */ unsigned char Index : 1; /* bit position: 0 */
                  /* 0x0003 */ unsigned char Processor : 5; /* bit position: 1 */
                  /* 0x0003 */ unsigned char Inserted : 1; /* bit position: 6 */
                  /* 0x0003 */ volatile unsigned char Expired : 1; /* bit position: 7 */
                }; /* bitfield */
                /* 0x0003 */ unsigned char DebugActive;
                /* 0x0003 */ unsigned char DpcActive;
                /* 0x0003 */ unsigned char Reserved5;
              }; /* size: 0x0001 */
            }; /* size: 0x0002 */
          }; /* size: 0x0002 */
        }; /* size: 0x0003 */
      }; /* size: 0x0003 */
    }; /* size: 0x0004 */
    /* 0x0000 */ volatile long Lock;
    /* 0x0000 */ long LockNV;
  }; /* size: 0x0004 */
  /* 0x0004 */ long SignalState;
  /* 0x0008 */ struct _LIST_ENTRY WaitListHead;
} DISPATCHER_HEADER, *PDISPATCHER_HEADER; /* size: 0x0010 */

typedef struct _KEVENT
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
} KEVENT, *PKEVENT; /* size: 0x0010 */

typedef enum _KRESOURCEMANAGER_STATE
{
  KResourceManagerUninitialized = 0,
  KResourceManagerOffline = 1,
  KResourceManagerOnline = 2,
} KRESOURCEMANAGER_STATE, *PKRESOURCEMANAGER_STATE;

typedef struct _KMUTANT
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
  /* 0x0010 */ struct _LIST_ENTRY MutantListEntry;
  /* 0x0018 */ struct _KTHREAD* OwnerThread;
  /* 0x001c */ unsigned char Abandoned;
  /* 0x001d */ unsigned char ApcDisable;
  /* 0x001e */ char __PADDING__[2];
} KMUTANT, *PKMUTANT; /* size: 0x0020 */

typedef struct _RTL_BALANCED_LINKS
{
  /* 0x0000 */ struct _RTL_BALANCED_LINKS* Parent;
  /* 0x0004 */ struct _RTL_BALANCED_LINKS* LeftChild;
  /* 0x0008 */ struct _RTL_BALANCED_LINKS* RightChild;
  /* 0x000c */ char Balance;
  /* 0x000d */ unsigned char Reserved[3];
} RTL_BALANCED_LINKS, *PRTL_BALANCED_LINKS; /* size: 0x0010 */

typedef struct _KTMOBJECT_NAMESPACE_LINK
{
  /* 0x0000 */ struct _RTL_BALANCED_LINKS Links;
  /* 0x0010 */ unsigned char Expired;
  /* 0x0011 */ char __PADDING__[3];
} KTMOBJECT_NAMESPACE_LINK, *PKTMOBJECT_NAMESPACE_LINK; /* size: 0x0014 */

typedef struct _GUID
{
  /* 0x0000 */ unsigned long Data1;
  /* 0x0004 */ unsigned short Data2;
  /* 0x0006 */ unsigned short Data3;
  /* 0x0008 */ unsigned char Data4[8];
} GUID, *PGUID; /* size: 0x0010 */

typedef struct _KQUEUE
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
  /* 0x0010 */ struct _LIST_ENTRY EntryListHead;
  /* 0x0018 */ volatile unsigned long CurrentCount;
  /* 0x001c */ unsigned long MaximumCount;
  /* 0x0020 */ struct _LIST_ENTRY ThreadListHead;
} KQUEUE, *PKQUEUE; /* size: 0x0028 */

typedef struct _UNICODE_STRING
{
  /* 0x0000 */ unsigned short Length;
  /* 0x0002 */ unsigned short MaximumLength;
  /* 0x0004 */ unsigned short* Buffer;
} UNICODE_STRING, *PUNICODE_STRING; /* size: 0x0008 */

typedef struct _RTL_AVL_TABLE
{
  /* 0x0000 */ struct _RTL_BALANCED_LINKS BalancedRoot;
  /* 0x0010 */ void* OrderedPointer;
  /* 0x0014 */ unsigned long WhichOrderedElement;
  /* 0x0018 */ unsigned long NumberGenericTableElements;
  /* 0x001c */ unsigned long DepthOfTree;
  /* 0x0020 */ struct _RTL_BALANCED_LINKS* RestartKey;
  /* 0x0024 */ unsigned long DeleteCount;
  /* 0x0028 */ void* CompareRoutine /* function */;
  /* 0x002c */ void* AllocateRoutine /* function */;
  /* 0x0030 */ void* FreeRoutine /* function */;
  /* 0x0034 */ void* TableContext;
} RTL_AVL_TABLE, *PRTL_AVL_TABLE; /* size: 0x0038 */

typedef struct _KTMOBJECT_NAMESPACE
{
  /* 0x0000 */ struct _RTL_AVL_TABLE Table;
  /* 0x0038 */ struct _KMUTANT Mutex;
  /* 0x0058 */ unsigned short LinksOffset;
  /* 0x005a */ unsigned short GuidOffset;
  /* 0x005c */ unsigned char Expired;
  /* 0x005d */ char __PADDING__[3];
} KTMOBJECT_NAMESPACE, *PKTMOBJECT_NAMESPACE; /* size: 0x0060 */

typedef struct _KRESOURCEMANAGER_COMPLETION_BINDING
{
  /* 0x0000 */ struct _LIST_ENTRY NotificationListHead;
  /* 0x0008 */ void* Port;
  /* 0x000c */ unsigned long Key;
  /* 0x0010 */ struct _EPROCESS* BindingProcess;
} KRESOURCEMANAGER_COMPLETION_BINDING, *PKRESOURCEMANAGER_COMPLETION_BINDING; /* size: 0x0014 */

typedef struct _KRESOURCEMANAGER
{
  /* 0x0000 */ struct _KEVENT NotificationAvailable;
  /* 0x0010 */ unsigned long cookie;
  /* 0x0014 */ enum _KRESOURCEMANAGER_STATE State;
  /* 0x0018 */ unsigned long Flags;
  /* 0x001c */ struct _KMUTANT Mutex;
  /* 0x003c */ struct _KTMOBJECT_NAMESPACE_LINK NamespaceLink;
  /* 0x0050 */ struct _GUID RmId;
  /* 0x0060 */ struct _KQUEUE NotificationQueue;
  /* 0x0088 */ struct _KMUTANT NotificationMutex;
  /* 0x00a8 */ struct _LIST_ENTRY EnlistmentHead;
  /* 0x00b0 */ unsigned long EnlistmentCount;
  /* 0x00b4 */ void* NotificationRoutine /* function */;
  /* 0x00b8 */ void* Key;
  /* 0x00bc */ struct _LIST_ENTRY ProtocolListHead;
  /* 0x00c4 */ struct _LIST_ENTRY PendingPropReqListHead;
  /* 0x00cc */ struct _LIST_ENTRY CRMListEntry;
  /* 0x00d4 */ struct _KTM* Tm;
  /* 0x00d8 */ struct _UNICODE_STRING Description;
  /* 0x00e0 */ struct _KTMOBJECT_NAMESPACE Enlistments;
  /* 0x0140 */ struct _KRESOURCEMANAGER_COMPLETION_BINDING CompletionBinding;
} KRESOURCEMANAGER, *PKRESOURCEMANAGER; /* size: 0x0154 */

