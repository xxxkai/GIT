#ifndef _CIOT_HUSSM_GPIO_H_
#define _CIOT_HUSSM_GPIO_H_

#include <stdio.h>
#include "ciot_common.h"

#ifdef  __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////
//
// Please add "-lwiringPi" option when compiling.
//
//////////////////////////////////////////////////////////////////////////
//
//---------------------------------------------------------
// Common
//---------------------------------------------------------
INT32 ciot_hussm_gpio_Initialize(void);
INT32 ciot_hussm_gpio_Finalize(void);

//////////////////////////////////////////////////////////////////////////
//
//---------------------------------------------------------
// Random
//---------------------------------------------------------
INT32 ciot_hussm_gpio_GenerateRandom(UINT32 numberLen, BYTE* pbOutput);


//---------------------------------------------------------
// Hash
//---------------------------------------------------------
INT32 ciot_hussm_gpio_HashData(HASH_BASE_PARAM* base, HASH_SALT_PARAM* salt, BYTE* pbInput, UINT32 inputLen, BYTE* pbOutput, UINT32* pOutputLen);


//---------------------------------------------------------
// Key
//---------------------------------------------------------

INT32 ciot_hussm_gpio_GetPubKeyInfo(PUB_KEY_INFO* pubKeyInfo);
INT32 ciot_hussm_gpio_ECDHComputeKey(BYTE* pbPubKey, UINT32 pPubKeyLen, BYTE* pbDerKey, UINT32* pDerKeyLen);


//---------------------------------------------------------
// Sign
//---------------------------------------------------------
INT32 ciot_hussm_gpio_SignInitialize(void);
INT32 ciot_hussm_gpio_SignData(UINT32 orgDataLen, UINT8 * pOrgData, UINT32 * pSignedDataLen, UINT8 * pSignedData);
INT32 ciot_hussm_gpio_VerifySign(UINT32 msgLen, UINT8 * pMessage, UINT32 signedDataLen, UINT8 * pSignedData);


//---------------------------------------------------------
// Symmetric Crypto
//---------------------------------------------------------
INT32 ciot_hussm_gpio_EncryptData(INT32 algoID, HUSSM_BLOCK_CIPHER_PARAM* param, BYTE* pbInput, UINT32 inputLen, BYTE* pbOutput, UINT32* pOutputLen);
INT32 ciot_hussm_gpio_DecryptData(INT32 algoID, HUSSM_BLOCK_CIPHER_PARAM* param, BYTE* pbInput, UINT32 inputLen, BYTE* pbOutput, UINT32* pOutputLen);

#endif