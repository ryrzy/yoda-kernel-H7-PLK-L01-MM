

#ifndef __BST_IP_SOCKET_H__
#define __BST_IP_SOCKET_H__
/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/

#include "BST_Platform.h"
#include "BST_IP_Define.h"
#include "BST_IP_LwipApi.h"
#include "BST_IP_RcverMng.h"

#if (BST_OS_VER == BST_HISI_VOS)
#pragma pack(4)
#elif(BST_OS_VER == BST_WIN32)
#pragma pack(push, 4)
#endif

/*****************************************************************************
  2 宏定义
*****************************************************************************/

/*****************************************************************************
  3 Massage Declare
*****************************************************************************/

/*****************************************************************************
  4 枚举定义
*****************************************************************************/


/*****************************************************************************
  5 类/结构定义
*****************************************************************************/


/*****************************************************************************
 类名      : BST_IP_CSocket
 协议表格  :
 ASN.1描述 :
 结构说明  : 定义socket操作的基类
*****************************************************************************/
class BST_IP_CSocket
{
BST_PUBLIC:
#if( BST_VER_TYPE == BST_DBG_VER )
    BST_IP_CSocket  (
        BST_PROCID_T    usProcId,
        BST_TASKID_T    usTaskId );
#else
    BST_IP_CSocket  ( BST_VOID );
#endif
    /*父类指针指向子类在析构时可以析构子类*/
    virtual        ~BST_IP_CSocket  ( BST_VOID );
    BST_IP_ERR_T    Connect         ( BST_VOID );
    BST_IP_ERR_T    Bind            ( BST_VOID );
    BST_IP_ERR_T    Close           ( BST_VOID );
    BST_IP_ERR_T    Socket          ( BST_VOID );
    BST_IP_ERR_T    Clone           ( BST_VOID );
    BST_IP_ERR_T    FreePcb         ( BST_VOID );

    BST_IP_ERR_T    Write           (
        const  BST_UINT8           *pucSdu,
        BST_UINT16                  usLength );

    BST_IP_ERR_T    Read            (
        BST_UINT8                  *pucSdu,
        BST_UINT16                  usLength );

    BST_IP_ERR_T    IoCtrl          (
        BST_SCKT_CMD_ENUM_UINT32    enCmd,
        BST_VOID                   *pvPara );

    /*
     * 增加ProcId和TaskId
     */
#if( BST_VER_TYPE == BST_DBG_VER )
    const BST_PROCID_T              m_usProcId;
    const BST_TASKID_T              m_usTaskId;
#endif
BST_PROTECTED:
    BST_IP_ERR_T    SetAddr         ( BST_IP_SOCKET_ADD_T      *pstAddress );

    BST_IP_ERR_T    SetPrpty        ( BST_IP_SKT_PROPTY_STRU   *pstProperty );

    BST_IP_ERR_T    GetPrpty        ( BST_IP_SKT_PROPTY_STRU   *pstProperty );

    BST_IP_ERR_T    InqFlow         (
        BST_UINT32                 *pTx,
        BST_UINT32                 *pRx );

    BST_IP_ERR_T    InqState        ( BST_VOID );

    BST_IP_ERR_T    RegCallBack     ( BST_IP_CNetRcver         *pC_CallBack );

    BST_IP_ERR_T    SetSocketType   ( BST_SCKT_TYPE_ENUM_UINT32 enSocketType );

    BST_IP_ERR_T    GetSocketFd     ( BST_FD_T                 *pSocketFd );

    BST_IP_ERR_T    GetTrafficFlow  (
        BST_IP_TRAFFIC_FLOW_STRU   *pstProperty,
        BST_UINT16                  usIsReset );

    BST_IP_ERR_T    SetTrafficFlow  (
        BST_IP_TRAFFIC_FLOW_STRU   *pstProperty );

BST_PRIVATE:
    BST_FD_T                            m_fd;
    /*for other message, eg. SSL Connect Context*/
    BST_ARG_T                           m_Arg;
    BST_IP_SOCKET_ADD_T                 m_stIpAddress;
    BST_IP_CNetRcver                   *m_pCallBacks;
    const BST_IP_SOCKET_FUN_LUT_STRU   *m_pFunGroup;
    BST_SCKT_TYPE_ENUM_UINT32           m_enSocketType;
    BST_IP_TRAFFIC_FLOW_STRU            m_TrafficPool;
    BST_IP_ERR_T                        CheckConfig( BST_VOID ) const;
    BST_IP_ERR_T                        CheckFd( const BST_FD_T *pfd ) const;
    BST_IP_PROTOCOL_TYPE                GetProtoType( BST_VOID );
};

/*****************************************************************************
  6 UNION定义
*****************************************************************************/


/*****************************************************************************
  7 全局变量声明
*****************************************************************************/


/*****************************************************************************
  8 函数声明
*****************************************************************************/

/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/

#if (BST_OS_VER == BST_HISI_VOS)
#pragma pack()
#elif(BST_OS_VER == BST_WIN32)
#pragma pack(pop)
#endif



#endif
