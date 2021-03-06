
#ifndef _NAS_SM_MULTI_MODE_H_
#define _NAS_SM_MULTI_MODE_H_

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

#if (FEATURE_ON == FEATURE_LTE)

/*****************************************************************************
  2 宏定义
*****************************************************************************/


/*****************************************************************************
  3 枚举定义
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/


/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/

/*****************************************************************************
 函 数 名  : NAS_SM_SndRabmBearerActivateInd
 功能描述  : 发送ID_SM_RABM_BEARER_ACTIVATE_IND至RABM
 输入参数  : ucNsapi        - 取值范围[5, 15]
             pstPdpCtxInfo  - PDP实体信息
 输出参数  : 无
 返 回 值  : VOS_OK         - 消息发送成功
             VOS_ERR        - 消息发送失败
 调用函数  :
 被调函数  :
*****************************************************************************/
VOS_UINT32 NAS_SM_SndRabmBearerActivateInd(
    VOS_UINT8                           ucNsapi,
    NAS_SM_PDP_CONTEXT_INFO_STRU       *pstPdpCtxInfo
);


/*****************************************************************************
 函 数 名  : NAS_SM_SndRabmBearerModifyInd
 功能描述  : 发送ID_SM_RABM_BEARER_MODIFY_IND至RABM
 输入参数  : ucNsapi        - 取值范围[5, 15]
             pstPdpCtxInfo  - PDP实体信息
 输出参数  : 无
 返 回 值  : VOS_OK         - 消息发送成功
             VOS_ERR        - 消息发送失败
 调用函数  :
 被调函数  :
*****************************************************************************/
VOS_UINT32 NAS_SM_SndRabmBearerModifyInd(
    VOS_UINT8                           ucNsapi,
    NAS_SM_PDP_CONTEXT_INFO_STRU       *pstPdpCtxInfo
);


/*****************************************************************************
 函 数 名  : NAS_SM_SndRabmBearerDeactivateInd
 功能描述  : 发送ID_SM_RABM_BEARER_ACTIVATE_IND至RABM
 输入参数  : ucNsapi        - 取值范围[5, 15]
             pstPdpCtxInfo  - PDP实体信息
 输出参数  : 无
 返 回 值  : VOS_OK         - 消息发送成功
             VOS_ERR        - 消息发送失败
 调用函数  :
 被调函数  :
*****************************************************************************/
VOS_UINT32 NAS_SM_SndRabmBearerDeactivateInd(
    VOS_UINT8                           ucNsapi,
    NAS_SM_PDP_CONTEXT_INFO_STRU       *pstPdpCtxInfo
);


/*****************************************************************************
 函 数 名  : NAS_SM_RcvTafBearerActivateInd
 功能描述  : 处理 ID_MN_SM_BEARER_ACTIVATE_IND 原语
 输入参数  : pstBearerActivateInd - ID_MN_SM_BEARER_ACTIVATE_IND消息内容
 输出参数  : 无
 返 回 值  : VOS_VOID
 调用函数  :
 被调函数  :
*****************************************************************************/
VOS_VOID NAS_SM_RcvTafBearerActivateInd(
    SMREG_BEARER_ACTIVATE_IND_STRU     *pstBearerActivateInd
);


/*****************************************************************************
 函 数 名  : NAS_SM_RcvTafBearerModifyInd
 功能描述  : 处理 ID_MN_SM_BEARER_MODIFY_IND 原语
 输入参数  : pstBearerModifyInd - ID_MN_SM_BEARER_MODIFY_IND消息内容
 输出参数  : 无
 返 回 值  : VOS_VOID
 调用函数  :
 被调函数  :
*****************************************************************************/
VOS_VOID NAS_SM_RcvTafBearerModifyInd(
    SMREG_BEARER_MODIFY_IND_STRU       *pstBearerModifyInd
);


/*****************************************************************************
 函 数 名  : NAS_SM_RcvTafBearerDeactivateInd
 功能描述  : 处理 ID_MN_SM_BEARER_DEACTIVATE_IND 原语
 输入参数  : pstBearerDeactivateInd - ID_MN_SM_BEARER_DEACTIVATE_IND消息内容
 输出参数  : 无
 返 回 值  : VOS_VOID
 调用函数  :
 被调函数  :
*****************************************************************************/
VOS_VOID NAS_SM_RcvTafBearerDeactivateInd(
    SMREG_BEARER_DEACTIVATE_IND_STRU   *pstBearerDeactivateInd
);
#endif


#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif



#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif
