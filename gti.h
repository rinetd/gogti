// Copyright 2019 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a Apache-style
// license that can be found in the LICENSE file.

#ifndef gti_capi_h_
#define gti_capi_h_

// #include <stddef.h>
// #include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

//typedef int                                   gti_capi_bool_t;
typedef struct gti_capi_face_t   gti_capi_face_t;
typedef struct gti_capi_result_t gti_capi_result_t;


//GtiModel * GtiCreateModel(const char *modelFile);

//GtiTensor * GTI_GetTensor(char * path)；



//GtiTensor * GtiEvaluate(GtiModel *model,GtiTensor * input);
// typedef enum TENSOR_FORMAT{
// 	TENSOR_FORMAT_BINARY,  //default is char
// 	TENSOR_FORMAT_BINARY_INTEGER,
// 	TENSOR_FORMAT_BINARY_FLOAT,
// 	TENSOR_FORMAT_TEXT,
// 	TENSOR_FORMAT_JSON,
// 	TENSOR_FORMAT_BUT,
// }TENSOR_FORMAT;

typedef struct _tensor{
	int width;
	int height;
	int depth;
	int stride;
	void *buffer;
	int size;          //buffer size;
	char format;
	void *tag;         //customer tag. will be copied from the input tensor to output tensors.

    struct _tensor *next;   //GTI reserved for future use.
	void *callbackFn;  //GTI internal use, don't touch.
}tensor_t;


typedef void * model_t;
// typedef void * tensor_t;
// void * GtiCreateModel(const char *path);
void * GTI_NewModel(char * path);
void * GTI_NewTensor(char * path);
//Tensor * GtiEval(model_t model,tensor_t tensor);
void * GTI_Predict(void *model, char * path);
tensor_t * GtiEval(void * model,void *  tensor);

// int run(int argc, char**argv);
// int run(int argc, char * mfile,char* tfile);
int run();

#ifdef __cplusplus
}
#endif
#endif // gti_capi_h_