/* Generated by Edge Impulse
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
// Generated on: 08.08.2021 11:28:08

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"

#if EI_CLASSIFIER_PRINT_STATE
#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C" {
    extern void ei_printf(const char *format, ...);
}
#else
extern void ei_printf(const char *format, ...);
#endif
#endif

#if defined __GNUC__
#define ALIGN(X) __attribute__((aligned(X)))
#elif defined _MSC_VER
#define ALIGN(X) __declspec(align(X))
#elif defined __TASKING__
#define ALIGN(X) __align(X)
#endif

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace {

constexpr int kTensorArenaSize = 7536;

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) __attribute__((section(".tensor_arena")));
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_RESHAPE, OP_CONV_2D, OP_MAX_POOL_2D, OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

TfLiteContext ctx{};
TfLiteTensor tflTensors[17];
TfLiteEvalTensor tflEvalTensors[17];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[8];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,689 } };
const TfArray<1, float> quant0_scale = { 1, { 0.050307877361774445, } };
const TfArray<1, int> quant0_zero = { 1, { 11 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(8) int32_t tensor_data1[2] = { -1, 896, };
const TfArray<1, int> tensor_dimension1 = { 1, { 2 } };
const ALIGN(8) int32_t tensor_data2[4] = { 1, 53, 13, 1, };
const TfArray<1, int> tensor_dimension2 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data3[8] = { -704, -614, -1330, -1251, -1251, -883, -1031, -1095, };
const TfArray<1, int> tensor_dimension3 = { 1, { 8 } };
const TfArray<8, float> quant3_scale = { 8, { 0.00010472491703694686, 9.6359151939395815e-05, 0.00010699756239773706, 9.2042238975409418e-05, 8.2086567999795079e-05, 4.5485492591978982e-05, 9.6440562629140913e-05, 7.9083445598371327e-05, } };
const TfArray<8, int> quant3_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant3 = { (TfLiteFloatArray*)&quant3_scale, (TfLiteIntArray*)&quant3_zero, 0 };
const ALIGN(8) int32_t tensor_data4[16] = { -1374, -6737, -4502, -3493, -2041, -852, -1562, -4861, -2052, -2549, -2409, -1649, -2745, -5602, -6284, -3229, };
const TfArray<1, int> tensor_dimension4 = { 1, { 16 } };
const TfArray<16, float> quant4_scale = { 16, { 1.8066210031975061e-05, 1.7520635083201341e-05, 2.087241955450736e-05, 1.8383043425274082e-05, 1.915097345772665e-05, 1.8490587535779923e-05, 2.1272746380418539e-05, 1.7331434719380923e-05, 1.7180011127493344e-05, 1.8070988517138176e-05, 1.9596049241954461e-05, 2.0143505025771447e-05, 1.6814596165204421e-05, 1.5474175597773865e-05, 1.522711681900546e-05, 2.1354217096813954e-05, } };
const TfArray<16, int> quant4_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant4 = { (TfLiteFloatArray*)&quant4_scale, (TfLiteIntArray*)&quant4_zero, 0 };
const ALIGN(8) int32_t tensor_data5[2] = { -1167, 1167, };
const TfArray<1, int> tensor_dimension5 = { 1, { 2 } };
const TfArray<1, float> quant5_scale = { 1, { 1.0116756129718851e-05, } };
const TfArray<1, int> quant5_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant5 = { (TfLiteFloatArray*)&quant5_scale, (TfLiteIntArray*)&quant5_zero, 0 };
const ALIGN(8) int8_t tensor_data6[2*896] = { 
  16, -70, 53, 3, 65, -11, 68, 75, 68, 68, 46, 40, 3, 52, 25, -23, 75, 18, 39, -5, 20, 77, -16, 26, -51, -33, 69, 10, 56, 52, -4, 58, 47, 35, 9, -14, 58, -20, 52, 42, -10, 55, 25, 84, -8, -32, 38, 29, 4, -31, 77, 37, 21, 59, -8, 25, 79, -56, 57, 27, 0, -32, 9, 63, 29, -5, -32, -50, 5, -32, -22, 50, 4, -35, -22, 47, -7, -9, -56, -68, 7, 20, 28, 1, -4, 13, 28, -27, 0, -24, 2, 19, -51, 7, -1, 26, 38, 39, 56, 27, 10, -25, 43, 1, 39, 43, 26, 64, -30, -7, -4, 1, 60, 15, 11, 39, -29, -40, -20, 12, 52, -11, 44, 69, 9, 27, 44, 31, 47, -51, -1, 39, 19, 28, -50, 60, 50, -20, 59, 42, 26, 15, -33, -41, -2, -37, 30, 69, -8, 34, -31, 18, 44, 9, 74, 42, -20, -10, 25, -36, -5, 27, 34, 14, -17, -45, -17, 47, -34, -15, 24, 21, -28, 35, 65, -38, 27, 22, 8, 22, -14, -18, 37, 2, -39, 48, 10, 4, -26, 2, -27, 18, 1, -42, -55, -31, 7, 48, -41, -6, 17, -42, -37, 24, -40, -34, -48, -20, 70, -37, 50, 32, -32, 17, -6, 23, -27, 8, 38, -6, -6, 15, -1, 48, 26, -6, 21, -5, 59, 16, 10, 1, -3, 66, -56, 7, 15, -27, 57, 32, -25, -11, 17, 32, 11, 33, -53, -30, -26, 11, 21, -66, -20, 4, 6, -20, 71, -46, -1, 41, -50, 70, -41, -29, -24, 46, -49, 4, 0, -40, 14, -39, 60, 2, -68, 8, -25, 23, 20, 18, -30, 15, 50, 37, -30, -21, -18, 4, 20, 11, 20, 33, 3, -2, -22, -4, -18, 55, 64, 65, 2, -76, -27, 59, -70, 11, 11, -9, -48, 3, 51, -12, 11, -7, 28, -17, 31, 12, -51, 17, 12, 16, -36, -23, -6, -27, -66, 23, -36, -7, -2, 21, -31, 25, -83, -53, -2, -37, -4, 40, -42, 62, -23, 30, -27, -51, 39, 72, -29, -76, -50, -17, 43, 32, 35, -39, -7, -17, -43, -26, -12, 50, 40, 56, -50, -6, 9, 25, 55, -58, 69, 19, 11, -3, 24, -27, 28, -44, -11, -20, 56, -20, 51, 30, 47, -13, -35, -1, 27, 61, -57, -27, 69, 10, 27, 93, 46, 4, -41, -17, 64, 23, 31, 34, -22, 9, -19, -4, 39, 0, 56, -22, 49, 5, 25, -20, -23, 17, -27, -39, -15, -36, -40, 39, -12, -39, 45, 13, 55, 1, -20, -29, 70, -11, 21, 7, -19, -11, -33, 48, 26, -30, -28, -27, -13, -51, -60, -11, 37, -47, -22, -25, -49, 98, -97, 3, 18, -66, 23, 34, 51, -5, -37, -3, -6, -12, 36, 78, -26, 34, 31, -17, 63, -25, 13, 14, -49, 9, -51, 26, -33, 51, 47, -29, -29, 60, -64, 1, 0, 22, 2, 36, 21, 21, -22, 8, -23, -46, 27, -38, -2, 16, -56, 2, -2, -46, 41, 34, 57, 63, -18, -9, 52, -10, -24, 40, -95, 33, -69, 21, -13, -53, 15, 14, -36, -17, 27, -10, 34, -38, -26, 36, 10, -32, -44, 37, 50, 5, 34, -30, 33, -12, -60, 51, 58, 36, -50, -19, -45, -20, -21, -2, 81, 20, 66, 53, 45, -7, -17, 16, 23, -2, 15, -24, 11, 3, -33, 53, 52, -10, 34, 80, 72, 54, 36, 27, 20, 5, -52, 15, 18, 68, -111, -13, -16, 57, -36, -18, 36, -29, -34, -28, 65, 33, -36, 14, -23, -19, 1, -17, 64, 54, 2, 73, 40, 16, -20, -40, 18, 50, 36, 32, 20, -25, -24, 24, -30, -24, -23, 95, -4, 36, -43, 4, 22, -52, 70, 23, 15, -14, -58, -29, -40, -42, 64, 17, 42, 21, 4, -21, 13, -94, -2, 9, 16, -30, -53, -3, 12, -35, -43, 10, -13, 53, -18, -69, 28, -15, -57, -18, 0, -32, -48, -27, 29, 49, 57, 27, -8, 19, -3, -21, 27, 13, -17, -7, -49, 19, 22, -39, 21, 12, 0, 30, 48, 6, 11, -15, 37, 9, 68, 47, -8, -32, -71, 3, 82, -7, 37, -31, 31, -38, -35, -48, 5, -2, -47, -3, -17, 57, -60, -36, -21, -52, -15, 52, -1, -20, -67, -16, 4, -29, 35, 50, -63, -45, -24, -3, 10, 26, 55, 58, -53, 1, 22, -9, -25, 6, 3, 48, -24, 36, -22, -15, 39, -21, -2, 12, 28, 37, -14, -6, 57, -41, 31, -36, 12, -21, -39, 47, 37, 51, -16, 13, -41, 33, -49, -54, -20, -5, -14, 24, 10, 9, -17, 59, 11, -41, 34, 25, 50, 82, 29, -15, 4, -30, -27, 47, 5, 42, -42, -16, 34, 43, 19, 37, -31, -7, 6, -1, 35, 52, -27, 47, -21, -2, -41, -28, -28, 16, -58, 61, -9, 32, -52, 40, 49, 17, 10, 43, 8, 4, -35, 33, 17, 5, 78, -27, 2, 3, -11, -41, 0, -15, 35, -1, -37, 9, 6, 62, -19, -1, -38, -8, -35, 47, 58, 31, 46, 80, -8, -13, -36, -43, 38, 49, 46, -23, -6, -18, -20, -5, 47, 37, -43, -8, 5, 1, -13, 38, 17, -23, -9, 35, 17, -5, -27, 74, -4, 29, 28, 25, 5, -20, -41, 51, 10, 61, -38, 25, 62, -4, -34, 68, 67, 61, 
  1, -44, -64, -7, -13, 3, -13, -39, -53, -47, -42, -22, -6, -48, -47, -40, -32, -59, 31, 13, -49, -58, -19, -45, -34, -1, 38, -49, -44, -24, 24, 14, -54, -23, 1, -36, -54, -45, -11, -63, -56, -9, 0, -5, -28, -27, 6, 1, 40, 36, -39, 15, -16, -60, -13, 32, -43, -23, 9, -32, 2, -56, -3, -27, -63, 38, 11, -67, -15, -21, 69, -5, -10, -58, -25, -41, -24, 38, 6, 43, -59, 2, 39, -50, -34, -49, 48, -4, -55, -57, -10, -103, 27, 18, 11, -23, -2, 30, 42, -15, -15, 21, 40, -6, 18, -26, -29, -52, -45, -21, 22, 0, -34, -56, -1, -48, -13, -52, 21, 21, 0, 16, -26, -17, -32, -60, -16, -38, -55, 48, 20, 25, 15, -59, 44, -25, 42, 19, 6, -7, -30, 50, 35, 40, 13, -20, 17, 14, 62, -58, 27, -51, 23, 17, -10, -23, 56, -13, 17, -53, 2, 18, 39, 26, 49, 28, 13, 21, -65, -59, 41, -54, -66, 4, 31, -15, 28, 33, -3, 25, -77, -10, 26, 3, -67, 34, -4, 36, 13, 19, -10, -18, -1, 46, 6, -29, 76, -81, 55, -16, 64, 0, 55, 14, 70, 39, 55, 70, 13, -6, 9, -49, 7, -75, 14, -9, -70, 20, -66, -29, 38, -33, -41, -47, 10, 0, 26, 59, 43, 59, 9, -41, 12, 8, 46, -44, 1, -65, 13, 28, -29, 28, 16, 38, -63, -27, -20, 25, 24, 68, 7, 3, 27, 7, 15, -9, 26, 63, 86, -4, 22, 38, 99, 4, -18, -36, -49, -35, 15, -4, 53, 42, -44, -2, -26, -21, -69, -33, 39, -13, -47, -32, -16, -69, 9, -22, 24, -17, 0, -16, 5, -19, -83, -37, -26, 30, -45, -32, 49, -44, 9, -7, 19, 31, -21, 18, -23, -62, 15, -31, 48, -21, -38, -45, 20, 5, 69, -3, -65, 2, -46, 94, 16, -5, 40, 30, -10, 35, -18, -27, -16, -72, 29, 51, 3, 39, -3, -18, -22, 26, 1, -19, 8, 24, -12, -15, 29, 45, 29, -10, 0, 0, 36, 62, 2, -30, -26, 14, 12, 23, -19, -44, 17, -9, -14, 36, 43, -28, 26, -54, -79, -50, -22, -15, -4, 26, -7, -9, 0, 33, -48, -59, 46, 1, -39, 21, 84, 11, 0, 26, 55, 11, 29, -33, -6, -27, 51, 21, 56, 96, 41, 41, 18, 17, 6, -46, 9, 3, -27, -21, -1, -81, -42, 44, 53, -14, -26, 12, 26, -37, 54, -19, 2, 42, -24, -23, 16, -76, 8, 26, -22, -11, -32, -18, -32, 26, 21, -48, 10, 59, -71, 51, 10, -63, -37, -18, -34, 21, -41, 38, 8, -68, 30, -16, 17, 47, -27, 16, 1, -69, 41, 64, 67, 78, 8, 5, 33, -38, 6, -12, 59, -14, -20, -75, -24, -37, -18, 29, -27, 15, -71, 48, 50, -68, -12, -62, -29, 33, -56, -4, -75, -99, 47, -34, -11, 31, -26, -58, 22, -42, 19, -7, -28, -43, -9, -63, -25, -12, 14, -69, 41, -36, -2, 46, 33, 2, 38, -16, 117, 54, 26, -3, 24, -57, -29, -18, 48, 59, 15, 10, 5, -42, 52, 35, 31, -39, 25, 9, -27, -79, 30, -19, -27, 50, -30, 23, -60, -12, -57, -2, 26, -39, 15, 1, 10, -84, 12, -37, -22, -3, -53, -52, -3, -47, -32, -69, 22, 5, -69, 23, -46, 11, -52, -11, 57, -35, -69, 46, 68, 27, 54, 42, 6, -7, -9, 36, 10, -78, 66, 8, 21, 66, 8, 23, -28, -10, 37, 36, 5, 18, 26, 11, -19, -3, 13, 57, 52, 12, -31, 39, 22, -52, 39, 29, -36, -30, 9, -63, -48, -43, 33, 36, 17, -66, -44, 13, 43, 44, -18, -48, -24, -18, -39, -40, -51, -61, -24, -38, -34, 8, -68, -7, -2, 46, 50, -30, 86, 2, 55, -10, 8, -43, -8, 58, 71, 48, -13, -33, -21, -41, 46, -11, -15, -35, -7, -1, -41, 31, -26, 6, 22, 25, -37, 47, -35, -20, -33, -36, 32, -19, -10, 4, -53, -24, 23, 28, -34, -53, 14, -35, -69, -55, 22, -48, -43, 11, -22, -17, -2, 30, 6, -53, 35, 23, -64, 29, 47, 27, 17, -12, 85, 24, 19, 10, -22, -27, 78, 9, 1, 59, -12, -32, 65, 23, 18, -62, 37, 11, -46, -27, 2, -17, -3, 34, -18, -30, -60, 3, 15, -55, 6, 31, 23, -19, -33, 21, -18, -46, -10, 27, 15, -1, 25, -42, -13, -9, -45, 57, 38, 9, -46, -9, 12, -23, 10, -49, -11, 39, -53, 11, 8, -2, 83, -17, 127, -21, 30, -24, -18, -38, -38, 9, 44, 37, 22, -29, -38, -41, 33, -13, 3, -13, -14, -51, -62, -23, -31, -69, -23, -8, 7, 21, -29, 0, 33, 36, -29, -66, -32, -5, 22, -49, 41, 12, -54, 29, -3, 14, -69, -11, 70, -47, -30, -46, -100, 61, -15, -74, -42, 26, 52, -38, 11, -20, -46, -39, 39, 14, 54, -63, -75, 5, -46, -38, 21, -40, -112, -63, -44, -76, 27, -86, 70, -46, 58, 10, -42, 2, -63, 9, -31, -62, -28, 64, 10, -57, -34, 0, 8, 57, 19, 47, 0, -64, 37, -87, -44, -64, -82, -15, -26, -64, -61, -49, 3, -15, 4, -21, -39, 41, -90, -18, -36, -12, 17, 27, 
};
const TfArray<2, int> tensor_dimension6 = { 2, { 2,896 } };
const TfArray<1, float> quant6_scale = { 1, { 0.0013522803783416748, } };
const TfArray<1, int> quant6_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const ALIGN(8) int8_t tensor_data7[8*3*3*1] = { 
  /* [0][0][][] */ -127, 22, -41, 
  /* [0][1][][] */ 85, 29, -43, 
  /* [0][2][][] */ 48, -7, 88, 
  /* [1][0][][] */ 17, 40, -22, 
  /* [1][1][][] */ -92, 87, 3, 
  /* [1][2][][] */ 64, -127, 11, 
  /* [2][0][][] */ 13, -95, -11, 
  /* [2][1][][] */ 118, -103, -13, 
  /* [2][2][][] */ -96, 127, -18, 
  /* [3][0][][] */ -27, 127, -78, 
  /* [3][1][][] */ 76, 126, -86, 
  /* [3][2][][] */ 28, 122, -58, 
  /* [4][0][][] */ 31, 77, -127, 
  /* [4][1][][] */ 45, 112, -120, 
  /* [4][2][][] */ 40, 59, -124, 
  /* [5][0][][] */ 76, 42, 18, 
  /* [5][1][][] */ 36, 116, -127, 
  /* [5][2][][] */ -104, -120, 107, 
  /* [6][0][][] */ -99, -37, -127, 
  /* [6][1][][] */ -91, -9, -70, 
  /* [6][2][][] */ 33, 26, -105, 
  /* [7][0][][] */ -37, -127, 51, 
  /* [7][1][][] */ 102, 67, -62, 
  /* [7][2][][] */ -74, 69, -8, 
};
const TfArray<4, int> tensor_dimension7 = { 4, { 8,3,3,1 } };
const TfArray<8, float> quant7_scale = { 8, { 0.0020816803444176912, 0.0019153889734297991, 0.0021268550772219896, 0.0018295790068805218, 0.001631684135645628, 0.00090414256555959582, 0.0019170071464031935, 0.0015719892689958215, } };
const TfArray<8, int> quant7_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const ALIGN(8) int8_t tensor_data8[16*3*3*8] = { 
  /* [0][0][][] */ -84,-46,-92,68,-30,-110,79,-78, 54,-46,-92,-12,-12,-110,40,-73, 59,-50,50,95,60,71,74,0, 
  /* [0][1][][] */ 50,-63,-89,63,6,-72,-57,41, -3,-35,34,21,-15,-66,-41,-123, -54,35,-73,44,127,48,36,29, 
  /* [0][2][][] */ -22,-58,-98,56,22,-109,-6,7, 10,-29,-97,-3,-9,-81,-118,-110, -65,-15,-69,53,-3,15,46,93, 
  /* [1][0][][] */ -38,127,-34,-70,-13,-32,63,77, -64,-37,-31,18,-74,38,-18,-1, 44,63,6,29,21,-38,-85,-5, 
  /* [1][1][][] */ 117,-34,8,79,53,50,43,54, -59,56,109,-29,-21,-28,-62,-59, -79,-14,93,-30,-25,-45,28,87, 
  /* [1][2][][] */ 82,28,87,66,-68,44,-78,-24, -40,58,-18,-45,-17,-112,-59,22, -73,32,25,1,18,-56,58,-11, 
  /* [2][0][][] */ -70,59,-51,-66,-13,61,-81,-69, 56,-8,-21,78,26,-60,-51,47, -34,-70,-50,-72,-31,-3,3,-1, 
  /* [2][1][][] */ 47,85,127,54,36,70,-3,-6, 58,-5,-62,-2,33,-40,-14,0, 19,-29,30,36,-25,32,-74,37, 
  /* [2][2][][] */ -12,49,70,-25,26,74,22,17, 25,7,-8,7,-6,51,-31,-41, 5,82,28,-53,-71,-53,8,43, 
  /* [3][0][][] */ -65,-20,-31,18,-5,56,-56,32, -42,-48,4,93,97,43,72,-39, -24,-94,33,-12,-49,25,56,-51, 
  /* [3][1][][] */ -24,-95,-79,68,75,-49,-49,23, -11,35,61,36,11,-36,27,-15, -52,-41,-31,8,-10,-33,-1,-12, 
  /* [3][2][][] */ -88,-98,18,89,-50,19,-88,-127, -94,10,49,71,-23,-67,82,-66, -87,12,17,-126,-26,29,54,23, 
  /* [4][0][][] */ 44,71,115,12,44,-5,-15,112, -91,26,37,-37,-45,-54,36,127, 92,-64,74,37,-43,90,-50,84, 
  /* [4][1][][] */ -20,39,-93,-12,-77,5,-82,-66, -30,-45,11,-46,37,49,-86,5, -18,-93,-25,44,-70,-12,-46,-14, 
  /* [4][2][][] */ -7,-25,5,23,-82,0,-83,16, 23,18,-89,45,-57,-16,-51,65, -34,72,54,-28,31,-7,-62,-80, 
  /* [5][0][][] */ 54,-48,-115,32,36,71,-10,50, -55,-91,-100,59,26,55,-74,-85, -28,15,50,8,76,3,-66,67, 
  /* [5][1][][] */ -79,30,-15,6,-100,-67,-41,34, -8,-47,-36,-39,35,-27,-71,-87, -58,94,4,18,-32,7,77,51, 
  /* [5][2][][] */ -71,-106,-18,73,-83,63,-127,-46, -28,68,-34,-37,57,56,31,-43, -93,-12,62,54,34,58,67,-14, 
  /* [6][0][][] */ 95,62,73,48,0,77,-46,109, 34,11,39,-47,-29,90,-8,-55, -31,60,-5,-42,-1,-31,-27,-18, 
  /* [6][1][][] */ 21,67,3,-57,-80,52,-12,-13, 69,11,-53,24,-20,18,38,-62, -40,15,-23,-29,-51,49,0,-50, 
  /* [6][2][][] */ 5,47,42,-1,17,93,-38,127, 35,87,-67,-41,-85,93,-46,37, 3,30,-46,4,0,35,-19,76, 
  /* [7][0][][] */ -63,-82,40,-29,-48,40,65,-2, 17,-92,-85,-11,75,2,48,-127, -103,-95,-84,-19,41,-4,-73,49, 
  /* [7][1][][] */ 33,-23,-87,38,68,55,3,-39, -17,54,102,48,31,-68,41,-17, 74,-102,-71,71,72,-32,28,-91, 
  /* [7][2][][] */ 35,57,60,-5,19,-102,-87,29, -94,-5,-37,40,-80,-35,-52,-50, 34,-15,68,-115,-22,-7,-41,19, 
  /* [8][0][][] */ -69,-61,57,-7,10,-47,22,61, -10,-54,-71,127,80,3,37,26, -3,-74,12,-106,7,-86,95,11, 
  /* [8][1][][] */ -36,-95,-54,-21,121,-97,42,35, 74,-54,26,-2,118,38,-23,57, -56,48,-28,75,-52,-17,62,-53, 
  /* [8][2][][] */ -14,-27,-97,104,-117,-124,36,-5, -18,42,15,-36,-1,-86,-61,-81, -61,-3,-45,-24,-73,-89,-24,-64, 
  /* [9][0][][] */ -25,-95,19,-45,72,52,-100,-32, -10,84,87,-78,14,35,95,-34, -60,-7,51,19,-8,-24,16,13, 
  /* [9][1][][] */ -84,20,20,97,80,-7,-48,-66, 6,18,-16,16,-24,48,18,-4, -43,-55,-50,-6,26,51,-127,14, 
  /* [9][2][][] */ -15,-32,-21,-20,-11,55,-1,35, -78,-64,-96,-73,78,-48,26,64, 65,-105,-100,-100,-8,18,-15,-70, 
  /* [10][0][][] */ -5,-30,18,11,29,-79,-58,-8, 87,6,12,41,127,17,65,-81, -18,-18,-14,-105,-33,-69,65,-36, 
  /* [10][1][][] */ 9,36,-2,68,-62,-39,-77,5, 6,-106,-56,10,26,-82,-92,-18, -96,60,36,-87,21,-80,-14,50, 
  /* [10][2][][] */ -18,-72,-85,68,12,3,-16,-12, 39,-75,46,33,-41,-19,9,-43, 1,2,72,-102,-79,-103,-50,-80, 
  /* [11][0][][] */ -1,-90,-50,76,25,-73,27,-32, -39,7,21,-30,-25,-35,32,31, 26,13,-79,99,121,-89,65,3, 
  /* [11][1][][] */ -40,-48,-79,48,45,12,-11,-36, -59,-80,32,24,5,-36,27,-99, 25,-58,-63,-33,45,0,8,-5, 
  /* [11][2][][] */ -63,-127,-53,82,98,-23,7,-104, -63,-52,-25,-8,-11,-82,-30,-68, -53,-25,19,79,95,-41,61,-54, 
  /* [12][0][][] */ 54,31,-114,-40,17,46,36,-104, -34,-31,64,-8,45,-100,41,20, -15,25,-68,-69,-19,61,-24,61, 
  /* [12][1][][] */ -88,56,8,40,54,70,-2,9, 23,-40,31,-112,8,37,-99,11, 81,-28,-114,18,-9,-79,-109,58, 
  /* [12][2][][] */ -36,-71,127,28,6,0,-13,89, -20,-52,-33,1,-82,-36,-63,-76, -62,63,-32,41,-38,-69,-83,-51, 
  /* [13][0][][] */ -6,26,-55,47,-88,-87,-24,-89, -104,-40,53,-54,38,-1,-87,-70, -57,-105,-48,11,-27,23,79,-31, 
  /* [13][1][][] */ 78,30,107,12,42,34,127,66, -22,50,54,-87,-5,82,-24,45, 117,-105,34,-65,-53,0,98,16, 
  /* [13][2][][] */ 21,47,17,-22,-22,21,117,-2, 44,-37,-64,-38,55,15,59,-88, -106,25,59,-22,29,44,-21,61, 
  /* [14][0][][] */ -22,12,54,-25,-126,125,-97,-126, 32,71,-65,15,92,-1,0,-23, -74,76,53,-89,-41,14,8,-29, 
  /* [14][1][][] */ -124,8,115,-115,-17,-60,47,7, -83,127,113,-28,-49,-67,34,112, 42,90,-88,33,-89,-127,57,-24, 
  /* [14][2][][] */ 36,35,-16,43,-57,-87,-46,78, 68,113,101,-53,-6,-106,-101,124, 39,10,80,-53,28,28,-14,-82, 
  /* [15][0][][] */ 41,17,-49,36,-65,-98,-91,-28, 6,57,25,-41,58,87,23,25, 40,-44,47,-60,-22,16,-55,11, 
  /* [15][1][][] */ -31,3,2,-112,-74,-59,-18,-38, 31,74,2,-15,-19,64,6,127, 21,-61,29,-37,-25,55,34,2, 
  /* [15][2][][] */ -90,-48,-13,-33,-8,-36,-114,3, 72,119,73,1,32,36,-43,-13, 16,-19,-58,-25,-35,54,9,49, 
};
const TfArray<4, int> tensor_dimension8 = { 4, { 16,3,3,8 } };
const TfArray<16, float> quant8_scale = { 16, { 0.0016326345503330231, 0.0015833311481401324, 0.0018862301949411631, 0.0016612665494903922, 0.0017306639347225428, 0.0016709852498024702, 0.0019224075367674232, 0.0015662332298234105, 0.0015525490744039416, 0.0016330663347616792, 0.0017708853119984269, 0.0018203585641458631, 0.0015195267042145133, 0.0013983935350552201, 0.0013760670553892851, 0.001929769990965724, } };
const TfArray<16, int> quant8_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const TfArray<4, int> tensor_dimension9 = { 4, { 1,53,13,1 } };
const TfArray<1, float> quant9_scale = { 1, { 0.050307877361774445, } };
const TfArray<1, int> quant9_zero = { 1, { 11 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const TfArray<4, int> tensor_dimension10 = { 4, { 1,53,13,8 } };
const TfArray<1, float> quant10_scale = { 1, { 0.011065679602324963, } };
const TfArray<1, int> quant10_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant10 = { (TfLiteFloatArray*)&quant10_scale, (TfLiteIntArray*)&quant10_zero, 0 };
const TfArray<4, int> tensor_dimension11 = { 4, { 1,27,7,8 } };
const TfArray<1, float> quant11_scale = { 1, { 0.011065679602324963, } };
const TfArray<1, int> quant11_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant11 = { (TfLiteFloatArray*)&quant11_scale, (TfLiteIntArray*)&quant11_zero, 0 };
const TfArray<4, int> tensor_dimension12 = { 4, { 1,27,7,16 } };
const TfArray<1, float> quant12_scale = { 1, { 0.0074812560342252254, } };
const TfArray<1, int> quant12_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant12 = { (TfLiteFloatArray*)&quant12_scale, (TfLiteIntArray*)&quant12_zero, 0 };
const TfArray<4, int> tensor_dimension13 = { 4, { 1,14,4,16 } };
const TfArray<1, float> quant13_scale = { 1, { 0.0074812560342252254, } };
const TfArray<1, int> quant13_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant13 = { (TfLiteFloatArray*)&quant13_scale, (TfLiteIntArray*)&quant13_zero, 0 };
const TfArray<2, int> tensor_dimension14 = { 2, { 1,896 } };
const TfArray<1, float> quant14_scale = { 1, { 0.0074812560342252254, } };
const TfArray<1, int> quant14_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant14 = { (TfLiteFloatArray*)&quant14_scale, (TfLiteIntArray*)&quant14_zero, 0 };
const TfArray<2, int> tensor_dimension15 = { 2, { 1,2 } };
const TfArray<1, float> quant15_scale = { 1, { 0.01744086854159832, } };
const TfArray<1, int> quant15_zero = { 1, { 5 } };
const TfLiteAffineQuantization quant15 = { (TfLiteFloatArray*)&quant15_scale, (TfLiteIntArray*)&quant15_zero, 0 };
const TfArray<2, int> tensor_dimension16 = { 2, { 1,2 } };
const TfArray<1, float> quant16_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant16_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant16 = { (TfLiteFloatArray*)&quant16_scale, (TfLiteIntArray*)&quant16_zero, 0 };
const TfLiteReshapeParams opdata0 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs0 = { 2, { 0,2 } };
const TfArray<1, int> outputs0 = { 1, { 9 } };
const TfLiteConvParams opdata1 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs1 = { 3, { 9,7,3 } };
const TfArray<1, int> outputs1 = { 1, { 10 } };
const TfLitePoolParams opdata2 = { kTfLitePaddingSame, 2,2, 2,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs2 = { 1, { 10 } };
const TfArray<1, int> outputs2 = { 1, { 11 } };
const TfLiteConvParams opdata3 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs3 = { 3, { 11,8,4 } };
const TfArray<1, int> outputs3 = { 1, { 12 } };
const TfLitePoolParams opdata4 = { kTfLitePaddingSame, 2,2, 2,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs4 = { 1, { 12 } };
const TfArray<1, int> outputs4 = { 1, { 13 } };
const TfLiteReshapeParams opdata5 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs5 = { 2, { 13,1 } };
const TfArray<1, int> outputs5 = { 1, { 14 } };
const TfLiteFullyConnectedParams opdata6 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs6 = { 3, { 14,6,5 } };
const TfArray<1, int> outputs6 = { 1, { 15 } };
const TfLiteSoftmaxParams opdata7 = { 1 };
const TfArray<1, int> inputs7 = { 1, { 15 } };
const TfArray<1, int> outputs7 = { 1, { 16 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension0, 689, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 8, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant3))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 64, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant4))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 8, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant5))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 1792, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data7, (TfLiteIntArray*)&tensor_dimension7, 72, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data8, (TfLiteIntArray*)&tensor_dimension8, 1152, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant8))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 5520, (TfLiteIntArray*)&tensor_dimension9, 689, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant9))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension10, 5512, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant10))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 5520, (TfLiteIntArray*)&tensor_dimension11, 1512, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant11))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension12, 3024, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant12))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 3024, (TfLiteIntArray*)&tensor_dimension13, 896, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant13))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension14, 896, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant14))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 896, (TfLiteIntArray*)&tensor_dimension15, 2, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant15))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension16, 2, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant16))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs4, (TfLiteIntArray*)&outputs4, const_cast<void*>(static_cast<const void*>(&opdata4)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs5, (TfLiteIntArray*)&outputs5, const_cast<void*>(static_cast<const void*>(&opdata5)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs6, (TfLiteIntArray*)&outputs6, const_cast<void*>(static_cast<const void*>(&opdata6)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs7, (TfLiteIntArray*)&outputs7, const_cast<void*>(static_cast<const void*>(&opdata7)), OP_SOFTMAX, },
};
static std::vector<void*> overflow_buffers;
static void * AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  if (current_location - bytes < tensor_boundary) {
    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    ptr = ei_calloc(bytes, 1);
    if (ptr == NULL) {
      printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return NULL;
    }
    overflow_buffers.push_back(ptr);
    return ptr;
  }

  current_location -= bytes;

  ptr = current_location;
  memset(ptr, 0, bytes);

  return ptr;
}
typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;
static std::vector<scratch_buffer_t> scratch_buffers;

static TfLiteStatus RequestScratchBufferInArena(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBuffer(ctx, b.bytes);
  if (!b.ptr) {
    return kTfLiteError;
  }

  scratch_buffers.push_back(b);

  *buffer_idx = scratch_buffers.size() - 1;

  return kTfLiteOk;
}

static void* GetScratchBuffer(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > static_cast<int>(scratch_buffers.size()) - 1) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static TfLiteTensor* GetTensor(const struct TfLiteContext* context,
                               int tensor_idx) {
  return &tflTensors[tensor_idx];
}

static TfLiteEvalTensor* GetEvalTensor(const struct TfLiteContext* context,
                                       int tensor_idx) {
  return &tflEvalTensors[tensor_idx];
}

} // namespace

TfLiteStatus trained_model_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#else
  memset(tensor_arena, 0, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;
  ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArena;
  ctx.GetScratchBuffer = &GetScratchBuffer;
  ctx.GetTensor = &GetTensor;
  ctx.GetEvalTensor = &GetEvalTensor;
  ctx.tensors = tflTensors;
  ctx.tensors_size = 17;
  for(size_t i = 0; i < 17; ++i) {
    tflTensors[i].type = tensorData[i].type;
    tflEvalTensors[i].type = tensorData[i].type;
    tflTensors[i].is_variable = 0;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    tflTensors[i].allocation_type = tensorData[i].allocation_type;
#else
    tflTensors[i].allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
    tflTensors[i].bytes = tensorData[i].bytes;
    tflTensors[i].dims = tensorData[i].dims;
    tflEvalTensors[i].dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    if(tflTensors[i].allocation_type == kTfLiteArenaRw){
      uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

     tflTensors[i].data.data =  start;
     tflEvalTensors[i].data.data =  start;
    }
    else{
       tflTensors[i].data.data = tensorData[i].data;
       tflEvalTensors[i].data.data = tensorData[i].data;
    }
#else
    tflTensors[i].data.data = tensorData[i].data;
    tflEvalTensors[i].data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
    tflTensors[i].quantization = tensorData[i].quantization;
    if (tflTensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
      tflTensors[i].params.scale = quant->scale->data[0];
      tflTensors[i].params.zero_point = quant->zero_point->data[0];
    }
    if (tflTensors[i].allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tflTensors[i].data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }
  if (tensor_boundary > current_location /* end of arena size */) {
    printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }
  registrations[OP_RESHAPE] = Register_RESHAPE();
  registrations[OP_CONV_2D] = Register_CONV_2D();
  registrations[OP_MAX_POOL_2D] = Register_MAX_POOL_2D();
  registrations[OP_FULLY_CONNECTED] = Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = Register_SOFTMAX();

  for(size_t i = 0; i < 8; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
    tflNodes[i].custom_initial_data = nullptr;
    tflNodes[i].custom_initial_data_size = 0;
    if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for(size_t i = 0; i < 8; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
TfLiteTensor* trained_model_input(int index) {
  return &ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  16, 
};
TfLiteTensor* trained_model_output(int index) {
  return &ctx.tensors[outTensorIndices[index]];
}

TfLiteStatus trained_model_invoke() {
  for(size_t i = 0; i < 8; ++i) {
    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);

#if EI_CLASSIFIER_PRINT_STATE
    ei_printf("layer %lu\n", i);
    ei_printf("    inputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].inputs->size; ix++) {
      auto d = tensorData[tflNodes[i].inputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");

    ei_printf("    outputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].outputs->size; ix++) {
      auto d = tensorData[tflNodes[i].outputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");
#endif // EI_CLASSIFIER_PRINT_STATE

    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus trained_model_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif
  scratch_buffers.clear();
  for (size_t ix = 0; ix < overflow_buffers.size(); ix++) {
    free(overflow_buffers[ix]);
  }
  overflow_buffers.clear();
  return kTfLiteOk;
}
