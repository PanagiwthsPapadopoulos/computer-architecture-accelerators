/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void image_diff_posterize_sw_ref( char (*llvm_cbe_A)[256],  char (*llvm_cbe_B)[256],  char (*llvm_cbe_C_ref)[256]);
void init_gradient_image( char (*llvm_cbe_img)[256], signed int llvm_cbe_offset, signed int llvm_cbe_scale);
void init_random_image( char (*llvm_cbe_img)[256], signed int llvm_cbe_seed);
void print_image_subset( char (*llvm_cbe_img)[256], signed int llvm_cbe_rows, signed int llvm_cbe_cols,  char *llvm_cbe_title);
void calculate_statistics( char (*llvm_cbe_C)[256]);
signed int main(void);
void apatb_image_diff_posterize_sw( char (*)[256],  char (*)[256],  char (*)[256]);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str[21] = "\n%s (%d*%d pixels):\n";
static  char aesl_internal__OC_str1[5] = "%3d ";
static  char aesl_internal__OC_str4[37] = "  Black pixels (0):     %d (%.2f%%)\n";
static  char aesl_internal__OC_str5[37] = "  Gray pixels (128):    %d (%.2f%%)\n";
static  char aesl_internal__OC_str6[37] = "  White pixels (255):   %d (%.2f%%)\n";
static  char aesl_internal__OC_str7[28] = "  Total pixels:         %d\n";
static  char aesl_internal_main_OC_A[256][256];
static  char aesl_internal_main_OC_B[256][256];
static  char aesl_internal_str15[33] = "\n--- Test Case 3: Edge Cases ---";
static  char aesl_internal__OC_str20[41] = "  First error at [%d][%d]: HW=%d, SW=%d\n";
static  char aesl_internal__OC_str14[8] = "Image B";
static  char aesl_internal__OC_str11[30] = "Thresholds: T1 = %d, T2 = %d\n";
static  char aesl_internal_str19[27] = "[PASS] Test Case 3 PASSED!";
static  char aesl_internal_str20[51] = "\n=================================================";
static  char aesl_internal_str[19] = "\nImage statistics:";
static  char aesl_internal__OC_str10[21] = "Dimensions: %d x %d\n";
static  char aesl_internal__OC_str13[8] = "Image A";
static  char aesl_internal__OC_str19[45] = "[FAIL] Test Case 1 FAILED! Found %d errors.\n";
static  char aesl_internal_str2[31] = "IMAGE_DIFF_POSTERIZE TESTBENCH";
static  char aesl_internal_str9[27] = "[PASS] Test Case 1 PASSED!";
static  char aesl_internal_str16[31] = "\nRunning software reference...";
static  char aesl_internal_str10[36] = "\n--- Test Case 2: Random Values ---";
static  char aesl_internal_str18[22] = "\nComparing results...";
static  char aesl_internal_str17[32] = "Running hardware accelerator...";
static  char aesl_internal__OC_str24[45] = "[FAIL] Test Case 2 FAILED! Found %d errors.\n";
static  char aesl_internal_str21[23] = "FINAL TESTBENCH RESULT";
static  char aesl_internal_main_OC_C_sw[256][256];
static  char aesl_internal__OC_str27[45] = "[FAIL] Test Case 3 FAILED! Found %d errors.\n";
static  char aesl_internal_str22[50] = "=================================================";
static  char aesl_internal__OC_str21[26] = "Output Image C (Hardware)";
static  char aesl_internal_str14[27] = "[PASS] Test Case 2 PASSED!";
static  char aesl_internal_main_OC_C_hw[256][256];
static  char aesl_internal_str5[40] = "\n--- Test Case 1: Gradient Patterns ---";
static  char aesl_internal_str26[54] = "Please check the hardware accelerator implementation.";
static  char aesl_internal_str24[38] = "Hardware accelerator works correctly.";
static  char aesl_internal_str23[25] = ">>> ALL TESTS PASSED <<<";
static  char aesl_internal_str25[26] = ">>> SOME TESTS FAILED <<<";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

void image_diff_posterize_sw_ref( char (*llvm_cbe_A)[256],  char (*llvm_cbe_B)[256],  char (*llvm_cbe_C_ref)[256]) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  unsigned long long llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
   char *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  unsigned char llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  unsigned short llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
   char *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned char llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned short llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  unsigned short llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  unsigned char llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned char llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  unsigned char llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_in_count = 0;
  unsigned char llvm_cbe__2e_in;
  unsigned char llvm_cbe__2e_in__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
   char *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
   char *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
   char *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @image_diff_posterize_sw_ref\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%31, %%30  for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__17);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = sext i32 %%storemerge3 to i64, !dbg !8 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__1 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__1);
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__18;

llvm_cbe_tmp__19:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%storemerge3, 1, !dbg !10 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_73_count);
  llvm_cbe_tmp__17 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__17&4294967295ull)));
  if (((llvm_cbe_tmp__17&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__20;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__17;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__18:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%.preheader ], [ %%29, %%28  for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__16);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%storemerge12 to i64, !dbg !8 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__2 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [256 x i8]* %%A, i64 %%1, i64 %%3, !dbg !8 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__3 = ( char *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__1))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__2))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__2) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i8* %%4, align 1, !dbg !8 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__4 = (unsigned char )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i8 %%5 to i16, !dbg !8 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__5 = (unsigned short )((unsigned short )(unsigned char )llvm_cbe_tmp__4&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [256 x i8]* %%B, i64 %%1, i64 %%3, !dbg !8 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__6 = ( char *)(&llvm_cbe_B[(((signed long long )llvm_cbe_tmp__1))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__2))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__2) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'B' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i8* %%7, align 1, !dbg !8 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__7 = (unsigned char )*llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = zext i8 %%8 to i16, !dbg !8 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__8 = (unsigned short )((unsigned short )(unsigned char )llvm_cbe_tmp__7&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sub i16 %%6, %%9, !dbg !8 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__9 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__5&65535ull)) - ((unsigned short )(llvm_cbe_tmp__8&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__9&65535ull)));
  if ((((signed short )llvm_cbe_tmp__9) < ((signed short )((unsigned short )0)))) {
    goto llvm_cbe_tmp__21;
  } else {
    goto llvm_cbe_tmp__22;
  }

llvm_cbe_tmp__23:
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add nsw i32 %%storemerge12, 1, !dbg !10 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__16 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__16&4294967295ull)));
  if (((llvm_cbe_tmp__16&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__19;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__16;   /* for PHI node */
    goto llvm_cbe_tmp__18;
  }

llvm_cbe_tmp__24:
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds [256 x i8]* %%C_ref, i64 %%1, i64 %%3, !dbg !9 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__13 = ( char *)(&llvm_cbe_C_ref[(((signed long long )llvm_cbe_tmp__1))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__2))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__2) < 256 && "Write access out of array 'C_ref' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%20, align 1, !dbg !9 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_52_count);
  *llvm_cbe_tmp__13 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
  goto llvm_cbe_tmp__23;

llvm_cbe_tmp__25:
if (AESL_DEBUG_TRACE)
printf("\n  %%.in = phi i8 [ %%14, %%12 ], [ %%16, %%15 ], !dbg !11 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe__2e_in_count);
  llvm_cbe__2e_in = (unsigned char )llvm_cbe__2e_in__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.in = 0x%X",llvm_cbe__2e_in);
printf("\n = 0x%X",llvm_cbe_tmp__11);
printf("\n = 0x%X",llvm_cbe_tmp__12);
}
  if ((((unsigned char )llvm_cbe__2e_in&255U) < ((unsigned char )((unsigned char )32)&255U))) {
    goto llvm_cbe_tmp__24;
  } else {
    goto llvm_cbe_tmp__26;
  }

llvm_cbe_tmp__21:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = trunc i16 %%10 to i8, !dbg !11 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__10 = (unsigned char )((unsigned char )llvm_cbe_tmp__9&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sub i8 0, %%13, !dbg !11 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__11 = (unsigned char )((unsigned char )(-(llvm_cbe_tmp__10)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__11&255ull)));
  llvm_cbe__2e_in__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__11;   /* for PHI node */
  goto llvm_cbe_tmp__25;

llvm_cbe_tmp__22:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = trunc i16 %%10 to i8, !dbg !11 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__12 = (unsigned char )((unsigned char )llvm_cbe_tmp__9&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__12);
  llvm_cbe__2e_in__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__12;   /* for PHI node */
  goto llvm_cbe_tmp__25;

llvm_cbe_tmp__27:
  goto llvm_cbe_tmp__23;

llvm_cbe_tmp__28:
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds [256 x i8]* %%C_ref, i64 %%1, i64 %%3, !dbg !9 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__14 = ( char *)(&llvm_cbe_C_ref[(((signed long long )llvm_cbe_tmp__1))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__2))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__2) < 256 && "Write access out of array 'C_ref' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 -128, i8* %%24, align 1, !dbg !9 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_57_count);
  *llvm_cbe_tmp__14 = ((unsigned char )128u);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )128u));
  goto llvm_cbe_tmp__27;

llvm_cbe_tmp__26:
  if ((((unsigned char )llvm_cbe__2e_in&255U) < ((unsigned char )((unsigned char )96)&255U))) {
    goto llvm_cbe_tmp__28;
  } else {
    goto llvm_cbe_tmp__29;
  }

llvm_cbe_tmp__29:
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds [256 x i8]* %%C_ref, i64 %%1, i64 %%3, !dbg !10 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__15 = ( char *)(&llvm_cbe_C_ref[(((signed long long )llvm_cbe_tmp__1))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__2))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__2) < 256 && "Write access out of array 'C_ref' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 -1, i8* %%26, align 1, !dbg !10 for 0x%I64xth hint within @image_diff_posterize_sw_ref  --> \n", ++aesl_llvm_cbe_60_count);
  *llvm_cbe_tmp__15 = ((unsigned char )-1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )-1));
  goto llvm_cbe_tmp__27;

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__20:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @image_diff_posterize_sw_ref}\n");
  return;
}


void init_gradient_image( char (*llvm_cbe_img)[256], signed int llvm_cbe_offset, signed int llvm_cbe_scale) {
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  unsigned long long llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  unsigned char llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  unsigned long long llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
   char *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  unsigned int llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @init_gradient_image\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%11, %%10  for 0x%I64xth hint within @init_gradient_image  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__38);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = mul nsw i32 %%storemerge3, %%scale, !dbg !9 for 0x%I64xth hint within @init_gradient_image  --> \n", ++aesl_llvm_cbe_100_count);
  llvm_cbe_tmp__30 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) * ((unsigned int )(llvm_cbe_scale&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__30&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add i32 %%1, %%offset, !dbg !9 for 0x%I64xth hint within @init_gradient_image  --> \n", ++aesl_llvm_cbe_101_count);
  llvm_cbe_tmp__31 = (unsigned int )((unsigned int )(llvm_cbe_tmp__30&4294967295ull)) + ((unsigned int )(llvm_cbe_offset&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__31&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%storemerge3 to i64, !dbg !8 for 0x%I64xth hint within @init_gradient_image  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__32 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__32);
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__39;

llvm_cbe_tmp__40:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add nsw i32 %%storemerge3, 1, !dbg !10 for 0x%I64xth hint within @init_gradient_image  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__38 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__38&4294967295ull)));
  if (((llvm_cbe_tmp__38&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__41;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__38;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__39:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%.preheader ], [ %%9, %%4  for 0x%I64xth hint within @init_gradient_image  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add i32 %%2, %%storemerge12, !dbg !9 for 0x%I64xth hint within @init_gradient_image  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__33 = (unsigned int )((unsigned int )(llvm_cbe_tmp__31&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge12&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__33&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = trunc i32 %%5 to i8, !dbg !8 for 0x%I64xth hint within @init_gradient_image  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__34 = (unsigned char )((unsigned char )llvm_cbe_tmp__33&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%storemerge12 to i64, !dbg !8 for 0x%I64xth hint within @init_gradient_image  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__35 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [256 x i8]* %%img, i64 %%3, i64 %%7, !dbg !8 for 0x%I64xth hint within @init_gradient_image  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__36 = ( char *)(&llvm_cbe_img[(((signed long long )llvm_cbe_tmp__32))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__35))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__32));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__35));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__35) < 256 && "Write access out of array 'img' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%6, i8* %%8, align 1, !dbg !8 for 0x%I64xth hint within @init_gradient_image  --> \n", ++aesl_llvm_cbe_109_count);
  *llvm_cbe_tmp__36 = llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add nsw i32 %%storemerge12, 1, !dbg !10 for 0x%I64xth hint within @init_gradient_image  --> \n", ++aesl_llvm_cbe_110_count);
  llvm_cbe_tmp__37 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__37&4294967295ull)));
  if (((llvm_cbe_tmp__37&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__40;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__37;   /* for PHI node */
    goto llvm_cbe_tmp__39;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__41:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @init_gradient_image}\n");
  return;
}


void init_random_image( char (*llvm_cbe_img)[256], signed int llvm_cbe_seed) {
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  unsigned long long llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  unsigned char llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  unsigned long long llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
   char *llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @init_random_image\n");
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @srand(i32 %%seed) nounwind, !dbg !9 for 0x%I64xth hint within @init_random_image  --> \n", ++aesl_llvm_cbe_129_count);
   /*tail*/ srand(llvm_cbe_seed);
if (AESL_DEBUG_TRACE) {
printf("\nArgument seed = 0x%X",llvm_cbe_seed);
}
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%9, %%8  for 0x%I64xth hint within @init_random_image  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__48);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = sext i32 %%storemerge3 to i64, !dbg !8 for 0x%I64xth hint within @init_random_image  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__42 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__42);
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__49;

llvm_cbe_tmp__50:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add nsw i32 %%storemerge3, 1, !dbg !9 for 0x%I64xth hint within @init_random_image  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__48 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__48&4294967295ull)));
  if (((llvm_cbe_tmp__48&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__51;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__48;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__49:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%.preheader ], [ %%7, %%2  for 0x%I64xth hint within @init_random_image  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__47);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = tail call i32 @rand() nounwind, !dbg !8 for 0x%I64xth hint within @init_random_image  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__43 = (unsigned int ) /*tail*/ rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__43);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = trunc i32 %%3 to i8, !dbg !8 for 0x%I64xth hint within @init_random_image  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__44 = (unsigned char )((unsigned char )llvm_cbe_tmp__43&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sext i32 %%storemerge12 to i64, !dbg !8 for 0x%I64xth hint within @init_random_image  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__45 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds [256 x i8]* %%img, i64 %%1, i64 %%5, !dbg !8 for 0x%I64xth hint within @init_random_image  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__46 = ( char *)(&llvm_cbe_img[(((signed long long )llvm_cbe_tmp__42))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__45))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__42));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__45));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__45) < 256 && "Write access out of array 'img' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%4, i8* %%6, align 1, !dbg !8 for 0x%I64xth hint within @init_random_image  --> \n", ++aesl_llvm_cbe_144_count);
  *llvm_cbe_tmp__46 = llvm_cbe_tmp__44;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%storemerge12, 1, !dbg !10 for 0x%I64xth hint within @init_random_image  --> \n", ++aesl_llvm_cbe_145_count);
  llvm_cbe_tmp__47 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__47&4294967295ull)));
  if (((llvm_cbe_tmp__47&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__50;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__47;   /* for PHI node */
    goto llvm_cbe_tmp__49;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__51:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @init_random_image}\n");
  return;
}


void print_image_subset( char (*llvm_cbe_img)[256], signed int llvm_cbe_rows, signed int llvm_cbe_cols,  char *llvm_cbe_title) {
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  unsigned int llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  unsigned int llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_putchar_2e_us_count = 0;
  unsigned int llvm_cbe_putchar_2e_us;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond8_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge15_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge15_2e_us;
  unsigned int llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  unsigned long long llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
   char *llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  unsigned char llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  unsigned int llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  unsigned int llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  unsigned int llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge6_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge6_2e_us;
  unsigned int llvm_cbe_storemerge6_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  unsigned long long llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge6_count = 0;
  unsigned int llvm_cbe_storemerge6;
  unsigned int llvm_cbe_storemerge6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_putchar_count = 0;
  unsigned int llvm_cbe_putchar;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  unsigned int llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond10_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @print_image_subset\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([21 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* %%title, i32 %%rows, i32 %%cols) nounwind, !dbg !9 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_168_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 21
#endif
])), ( char *)llvm_cbe_title, llvm_cbe_rows, llvm_cbe_cols);
if (AESL_DEBUG_TRACE) {
printf("\nArgument rows = 0x%X",llvm_cbe_rows);
printf("\nArgument cols = 0x%X",llvm_cbe_cols);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__52);
}
  if ((((signed int )llvm_cbe_rows) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e_critedge;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
  if ((((signed int )llvm_cbe_cols) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph_2e_split_2e_us;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph_2e__2e_preheader_2e_lr_2e_ph_2e_split_crit_edge;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph_2e__2e_preheader_2e_lr_2e_ph_2e_split_crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sub i32 0, %%rows, !dbg !9 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__53 = (unsigned int )-(llvm_cbe_rows);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__53&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = select i1 %%5, i32 %%rows, i32 256, !dbg !9 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__54 = (unsigned int )(((((unsigned int )llvm_cbe_tmp__53&4294967295U) > ((unsigned int )4294967040u&4294967295U))) ? ((unsigned int )llvm_cbe_rows) : ((unsigned int )256u));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__54);
  llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_critedge2;

llvm_cbe__2e_preheader_2e_lr_2e_ph_2e_split_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sub i32 0, %%cols, !dbg !9 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__55 = (unsigned int )-(llvm_cbe_cols);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__55&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = select i1 %%8, i32 %%cols, i32 256, !dbg !9 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__56 = (unsigned int )(((((unsigned int )llvm_cbe_tmp__55&4294967295U) > ((unsigned int )4294967040u&4294967295U))) ? ((unsigned int )llvm_cbe_cols) : ((unsigned int )256u));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sub i32 0, %%rows, !dbg !9 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__57 = (unsigned int )-(llvm_cbe_rows);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__57&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = select i1 %%11, i32 %%rows, i32 256, !dbg !9 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_187_count);
  llvm_cbe_tmp__58 = (unsigned int )(((((unsigned int )llvm_cbe_tmp__57&4294967295U) > ((unsigned int )4294967040u&4294967295U))) ? ((unsigned int )llvm_cbe_rows) : ((unsigned int )256u));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__58);
  llvm_cbe_storemerge6_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_lr_2e_ph_2e_us;

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge6.us = phi i32 [ 0, %%.preheader.lr.ph.split.us ], [ %%13, %%.critedge2.us  for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_storemerge6_2e_us_count);
  llvm_cbe_storemerge6_2e_us = (unsigned int )llvm_cbe_storemerge6_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge6.us = 0x%X",llvm_cbe_storemerge6_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__59);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = sext i32 %%storemerge6.us to i64, !dbg !8 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__66 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge6_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__66);
  llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__68;

llvm_cbe__2e_critedge2_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar.us = tail call i32 @putchar(i32 10) nounwind, !dbg !10 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_putchar_2e_us_count);
   /*tail*/ putchar(10u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn putchar.us = 0x%X",llvm_cbe_putchar_2e_us);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add nsw i32 %%storemerge6.us, 1, !dbg !10 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_189_count);
  llvm_cbe_tmp__59 = (unsigned int )((unsigned int )(llvm_cbe_storemerge6_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__59&4294967295ull)));
  if (((llvm_cbe_tmp__59&4294967295U) == (llvm_cbe_tmp__58&4294967295U))) {
    goto llvm_cbe__2e__2e_critedge_crit_edge;
  } else {
    llvm_cbe_storemerge6_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__59;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__68:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15.us = phi i32 [ 0, %%.lr.ph.us ], [ %%20, %%14  for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_storemerge15_2e_us_count);
  llvm_cbe_storemerge15_2e_us = (unsigned int )llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15.us = 0x%X",llvm_cbe_storemerge15_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__65);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sext i32 %%storemerge15.us to i64, !dbg !8 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_196_count);
  llvm_cbe_tmp__60 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge15_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds [256 x i8]* %%img, i64 %%21, i64 %%15, !dbg !8 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_197_count);
  llvm_cbe_tmp__61 = ( char *)(&llvm_cbe_img[(((signed long long )llvm_cbe_tmp__66))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__60))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__66));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__60));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__60) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'img' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i8* %%16, align 1, !dbg !8 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_198_count);
  llvm_cbe_tmp__62 = (unsigned char )*llvm_cbe_tmp__61;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = zext i8 %%17 to i32, !dbg !8 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_199_count);
  llvm_cbe_tmp__63 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__62&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 %%18) nounwind, !dbg !8 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_200_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__63);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__64);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add nsw i32 %%storemerge15.us, 1, !dbg !10 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_201_count);
  llvm_cbe_tmp__65 = (unsigned int )((unsigned int )(llvm_cbe_storemerge15_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__65&4294967295ull)));
  if (((llvm_cbe_tmp__65&4294967295U) == (llvm_cbe_tmp__56&4294967295U))) {
    goto llvm_cbe__2e_critedge2_2e_us;
  } else {
    llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__65;   /* for PHI node */
    goto llvm_cbe_tmp__68;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
  do {     /* Syntactic loop '.critedge2' to make GCC happy */
llvm_cbe__2e_critedge2:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge6 = phi i32 [ 0, %%.preheader.lr.ph..preheader.lr.ph.split_crit_edge ], [ %%22, %%.critedge2  for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_storemerge6_count);
  llvm_cbe_storemerge6 = (unsigned int )llvm_cbe_storemerge6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge6 = 0x%X",llvm_cbe_storemerge6);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__67);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar = tail call i32 @putchar(i32 10) nounwind, !dbg !10 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_putchar_count);
   /*tail*/ putchar(10u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn putchar = 0x%X",llvm_cbe_putchar);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add nsw i32 %%storemerge6, 1, !dbg !10 for 0x%I64xth hint within @print_image_subset  --> \n", ++aesl_llvm_cbe_218_count);
  llvm_cbe_tmp__67 = (unsigned int )((unsigned int )(llvm_cbe_storemerge6&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__67&4294967295ull)));
  if (((llvm_cbe_tmp__67&4294967295U) == (llvm_cbe_tmp__54&4294967295U))) {
    goto llvm_cbe__2e__2e_critedge_crit_edge;
  } else {
    llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__67;   /* for PHI node */
    goto llvm_cbe__2e_critedge2;
  }

  } while (1); /* end of syntactic loop '.critedge2' */
llvm_cbe__2e__2e_critedge_crit_edge:
  goto llvm_cbe__2e_critedge;

llvm_cbe__2e_critedge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @print_image_subset}\n");
  return;
}


void calculate_statistics( char (*llvm_cbe_C)[256]) {
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge8_count = 0;
  unsigned int llvm_cbe_storemerge8;
  unsigned int llvm_cbe_storemerge8__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  unsigned int llvm_cbe_tmp__69;
  unsigned int llvm_cbe_tmp__69__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  unsigned int llvm_cbe_tmp__70;
  unsigned int llvm_cbe_tmp__70__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  unsigned int llvm_cbe_tmp__71;
  unsigned int llvm_cbe_tmp__71__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  unsigned long long llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned int llvm_cbe_storemerge14;
  unsigned int llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  unsigned int llvm_cbe_tmp__73;
  unsigned int llvm_cbe_tmp__73__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  unsigned int llvm_cbe_tmp__74;
  unsigned int llvm_cbe_tmp__74__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  unsigned int llvm_cbe_tmp__75;
  unsigned int llvm_cbe_tmp__75__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  unsigned long long llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
   char *llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  unsigned char llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  unsigned int llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  unsigned int llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  unsigned int llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  unsigned int llvm_cbe_tmp__82;
  unsigned int llvm_cbe_tmp__82__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  unsigned int llvm_cbe_tmp__83;
  unsigned int llvm_cbe_tmp__83__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  unsigned int llvm_cbe_tmp__84;
  unsigned int llvm_cbe_tmp__84__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  unsigned int llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  unsigned int llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond11_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  double llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  double llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  double llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  unsigned int llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  double llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  double llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  double llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  unsigned int llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  double llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  double llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  double llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  unsigned int llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  unsigned int llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @calculate_statistics\n");
  llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__69__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__70__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__71__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8 = phi i32 [ 0, %%0 ], [ %%28, %%27  for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_storemerge8_count);
  llvm_cbe_storemerge8 = (unsigned int )llvm_cbe_storemerge8__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__86);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = phi i32 [ 0, %%0 ], [ %%25, %%27  for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_250_count);
  llvm_cbe_tmp__69 = (unsigned int )llvm_cbe_tmp__69__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__69);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__84);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = phi i32 [ 0, %%0 ], [ %%24, %%27  for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_251_count);
  llvm_cbe_tmp__70 = (unsigned int )llvm_cbe_tmp__70__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__70);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__83);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = phi i32 [ 0, %%0 ], [ %%23, %%27  for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_252_count);
  llvm_cbe_tmp__71 = (unsigned int )llvm_cbe_tmp__71__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__71);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__82);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i32 %%storemerge8 to i64, !dbg !8 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_258_count);
  llvm_cbe_tmp__72 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge8);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__72);
  llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__73__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__69;   /* for PHI node */
  llvm_cbe_tmp__74__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__70;   /* for PHI node */
  llvm_cbe_tmp__75__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__71;   /* for PHI node */
  goto llvm_cbe_tmp__100;

llvm_cbe_tmp__101:
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add nsw i32 %%storemerge8, 1, !dbg !10 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_300_count);
  llvm_cbe_tmp__86 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__86&4294967295ull)));
  if (((llvm_cbe_tmp__86&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__102;
  } else {
    llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__86;   /* for PHI node */
    llvm_cbe_tmp__69__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__84;   /* for PHI node */
    llvm_cbe_tmp__70__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__83;   /* for PHI node */
    llvm_cbe_tmp__71__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__82;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__100:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i32 [ 0, %%.preheader ], [ %%26, %%22  for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned int )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%X",llvm_cbe_storemerge14);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__85);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = phi i32 [ %%1, %%.preheader ], [ %%25, %%22  for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_260_count);
  llvm_cbe_tmp__73 = (unsigned int )llvm_cbe_tmp__73__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__73);
printf("\n = 0x%X",llvm_cbe_tmp__69);
printf("\n = 0x%X",llvm_cbe_tmp__84);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = phi i32 [ %%2, %%.preheader ], [ %%24, %%22  for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_261_count);
  llvm_cbe_tmp__74 = (unsigned int )llvm_cbe_tmp__74__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__74);
printf("\n = 0x%X",llvm_cbe_tmp__70);
printf("\n = 0x%X",llvm_cbe_tmp__83);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = phi i32 [ %%3, %%.preheader ], [ %%23, %%22  for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_262_count);
  llvm_cbe_tmp__75 = (unsigned int )llvm_cbe_tmp__75__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__75);
printf("\n = 0x%X",llvm_cbe_tmp__71);
printf("\n = 0x%X",llvm_cbe_tmp__82);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = sext i32 %%storemerge14 to i64, !dbg !8 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_263_count);
  llvm_cbe_tmp__76 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge14);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds [256 x i8]* %%C, i64 %%4, i64 %%9, !dbg !8 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_264_count);
  llvm_cbe_tmp__77 = ( char *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__72))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__76))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__72));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__76));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__76) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i8* %%10, align 1, !dbg !8 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_265_count);
  llvm_cbe_tmp__78 = (unsigned char )*llvm_cbe_tmp__77;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__78);
  if (((llvm_cbe_tmp__78&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__103;
  } else {
    goto llvm_cbe_tmp__104;
  }

llvm_cbe_tmp__105:
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = phi i32 [ %%8, %%13 ], [ %%8, %%17 ], [ %%., %%19  for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_289_count);
  llvm_cbe_tmp__82 = (unsigned int )llvm_cbe_tmp__82__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__82);
printf("\n = 0x%X",llvm_cbe_tmp__75);
printf("\n = 0x%X",llvm_cbe_tmp__75);
printf("\n. = 0x%X",llvm_cbe__2e_);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = phi i32 [ %%7, %%13 ], [ %%18, %%17 ], [ %%7, %%19  for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_290_count);
  llvm_cbe_tmp__83 = (unsigned int )llvm_cbe_tmp__83__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__83);
printf("\n = 0x%X",llvm_cbe_tmp__74);
printf("\n = 0x%X",llvm_cbe_tmp__80);
printf("\n = 0x%X",llvm_cbe_tmp__74);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = phi i32 [ %%14, %%13 ], [ %%6, %%17 ], [ %%6, %%19  for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_291_count);
  llvm_cbe_tmp__84 = (unsigned int )llvm_cbe_tmp__84__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__84);
printf("\n = 0x%X",llvm_cbe_tmp__79);
printf("\n = 0x%X",llvm_cbe_tmp__73);
printf("\n = 0x%X",llvm_cbe_tmp__73);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add nsw i32 %%storemerge14, 1, !dbg !11 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_292_count);
  llvm_cbe_tmp__85 = (unsigned int )((unsigned int )(llvm_cbe_storemerge14&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__85&4294967295ull)));
  if (((llvm_cbe_tmp__85&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__101;
  } else {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__85;   /* for PHI node */
    llvm_cbe_tmp__73__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__84;   /* for PHI node */
    llvm_cbe_tmp__74__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__83;   /* for PHI node */
    llvm_cbe_tmp__75__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__82;   /* for PHI node */
    goto llvm_cbe_tmp__100;
  }

llvm_cbe_tmp__103:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add nsw i32 %%6, 1, !dbg !9 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_268_count);
  llvm_cbe_tmp__79 = (unsigned int )((unsigned int )(llvm_cbe_tmp__73&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__79&4294967295ull)));
  llvm_cbe_tmp__82__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__75;   /* for PHI node */
  llvm_cbe_tmp__83__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__74;   /* for PHI node */
  llvm_cbe_tmp__84__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__79;   /* for PHI node */
  goto llvm_cbe_tmp__105;

llvm_cbe_tmp__106:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%7, 1, !dbg !10 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_276_count);
  llvm_cbe_tmp__80 = (unsigned int )((unsigned int )(llvm_cbe_tmp__74&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__80&4294967295ull)));
  llvm_cbe_tmp__82__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__75;   /* for PHI node */
  llvm_cbe_tmp__83__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__80;   /* for PHI node */
  llvm_cbe_tmp__84__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__73;   /* for PHI node */
  goto llvm_cbe_tmp__105;

llvm_cbe_tmp__104:
  if (((llvm_cbe_tmp__78&255U) == (((unsigned char )128u)&255U))) {
    goto llvm_cbe_tmp__106;
  } else {
    goto llvm_cbe_tmp__107;
  }

llvm_cbe_tmp__107:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add nsw i32 %%8, 1, !dbg !10 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_283_count);
  llvm_cbe_tmp__81 = (unsigned int )((unsigned int )(llvm_cbe_tmp__75&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__81&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%20, i32 %%21, i32 %%8, !dbg !9 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )((((llvm_cbe_tmp__78&255U) == (((unsigned char )-1)&255U))) ? ((unsigned int )llvm_cbe_tmp__81) : ((unsigned int )llvm_cbe_tmp__75));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
  llvm_cbe_tmp__82__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_;   /* for PHI node */
  llvm_cbe_tmp__83__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__74;   /* for PHI node */
  llvm_cbe_tmp__84__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__73;   /* for PHI node */
  goto llvm_cbe_tmp__105;

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__102:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = tail call i32 @puts(i8* getelementptr inbounds ([19 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !11 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_puts_count);
   /*tail*/ puts(( char *)((&aesl_internal_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 19
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = sitofp i32 %%25 to double, !dbg !9 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_308_count);
  llvm_cbe_tmp__87 = (double )((double )(signed int )llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__87, *(long long*)(&llvm_cbe_tmp__87));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = fmul double %%30, 1.000000e+02, !dbg !9 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_309_count);
  llvm_cbe_tmp__88 = (double )llvm_cbe_tmp__87 * 0x1.9p6;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__88, *(long long*)(&llvm_cbe_tmp__88));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = fmul double %%31, 0x3EF0000000000000, !dbg !9 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_310_count);
  llvm_cbe_tmp__89 = (double )llvm_cbe_tmp__88 * 0x1p-16;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__89, *(long long*)(&llvm_cbe_tmp__89));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([37 x i8]* @aesl_internal_.str4, i64 0, i64 0), i32 %%25, double %%32) nounwind, !dbg !9 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_311_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 37
#endif
])), llvm_cbe_tmp__84, llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__84);
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__89, *(long long*)(&llvm_cbe_tmp__89));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__90);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = sitofp i32 %%24 to double, !dbg !10 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_312_count);
  llvm_cbe_tmp__91 = (double )((double )(signed int )llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__91, *(long long*)(&llvm_cbe_tmp__91));
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = fmul double %%34, 1.000000e+02, !dbg !10 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_313_count);
  llvm_cbe_tmp__92 = (double )llvm_cbe_tmp__91 * 0x1.9p6;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__92, *(long long*)(&llvm_cbe_tmp__92));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = fmul double %%35, 0x3EF0000000000000, !dbg !10 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_314_count);
  llvm_cbe_tmp__93 = (double )llvm_cbe_tmp__92 * 0x1p-16;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__93, *(long long*)(&llvm_cbe_tmp__93));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([37 x i8]* @aesl_internal_.str5, i64 0, i64 0), i32 %%24, double %%36) nounwind, !dbg !10 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_315_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 37
#endif
])), llvm_cbe_tmp__83, llvm_cbe_tmp__93);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__83);
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__93, *(long long*)(&llvm_cbe_tmp__93));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__94);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = sitofp i32 %%23 to double, !dbg !10 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_316_count);
  llvm_cbe_tmp__95 = (double )((double )(signed int )llvm_cbe_tmp__82);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__95, *(long long*)(&llvm_cbe_tmp__95));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = fmul double %%38, 1.000000e+02, !dbg !10 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_317_count);
  llvm_cbe_tmp__96 = (double )llvm_cbe_tmp__95 * 0x1.9p6;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__96, *(long long*)(&llvm_cbe_tmp__96));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = fmul double %%39, 0x3EF0000000000000, !dbg !10 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_318_count);
  llvm_cbe_tmp__97 = (double )llvm_cbe_tmp__96 * 0x1p-16;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__97, *(long long*)(&llvm_cbe_tmp__97));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([37 x i8]* @aesl_internal_.str6, i64 0, i64 0), i32 %%23, double %%40) nounwind, !dbg !10 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_319_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 37
#endif
])), llvm_cbe_tmp__82, llvm_cbe_tmp__97);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__82);
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__97, *(long long*)(&llvm_cbe_tmp__97));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__98);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([28 x i8]* @aesl_internal_.str7, i64 0, i64 0), i32 65536) nounwind, !dbg !11 for 0x%I64xth hint within @calculate_statistics  --> \n", ++aesl_llvm_cbe_320_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
])), 65536u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",65536u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__99);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @calculate_statistics}\n");
  return;
}


signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_puts9_count = 0;
  unsigned int llvm_cbe_puts9;
  static  unsigned long long aesl_llvm_cbe_puts10_count = 0;
  unsigned int llvm_cbe_puts10;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  unsigned int llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  unsigned int llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_puts11_count = 0;
  unsigned int llvm_cbe_puts11;
  static  unsigned long long aesl_llvm_cbe_puts12_count = 0;
  unsigned int llvm_cbe_puts12;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts13_count = 0;
  unsigned int llvm_cbe_puts13;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts14_count = 0;
  unsigned int llvm_cbe_puts14;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts15_count = 0;
  unsigned int llvm_cbe_puts15;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge57_count = 0;
  unsigned int llvm_cbe_storemerge57;
  unsigned int llvm_cbe_storemerge57__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  unsigned int llvm_cbe_tmp__110;
  unsigned int llvm_cbe_tmp__110__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  unsigned int llvm_cbe_tmp__111;
  unsigned int llvm_cbe_tmp__111__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  unsigned int llvm_cbe_tmp__112;
  unsigned int llvm_cbe_tmp__112__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  unsigned long long llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge853_count = 0;
  unsigned int llvm_cbe_storemerge853;
  unsigned int llvm_cbe_storemerge853__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  unsigned int llvm_cbe_tmp__114;
  unsigned int llvm_cbe_tmp__114__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  unsigned int llvm_cbe_tmp__115;
  unsigned int llvm_cbe_tmp__115__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  unsigned int llvm_cbe_tmp__116;
  unsigned int llvm_cbe_tmp__116__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  unsigned long long llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
   char *llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  unsigned char llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
   char *llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  unsigned char llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  unsigned int llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge8_2e__count = 0;
  unsigned int llvm_cbe_storemerge8_2e_;
  static  unsigned long long aesl_llvm_cbe_storemerge_2e__count = 0;
  unsigned int llvm_cbe_storemerge_2e_;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  unsigned int llvm_cbe_tmp__123;
  unsigned int llvm_cbe_tmp__123__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  unsigned int llvm_cbe_tmp__124;
  unsigned int llvm_cbe_tmp__124__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  unsigned int llvm_cbe_tmp__125;
  unsigned int llvm_cbe_tmp__125__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  unsigned int llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond68_count = 0;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  unsigned int llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond69_count = 0;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts16_count = 0;
  unsigned int llvm_cbe_puts16;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  unsigned int llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
  unsigned long long llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
  unsigned long long llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
   char *llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  unsigned char llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  unsigned int llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
   char *llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
  unsigned char llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  unsigned int llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  unsigned int llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts17_count = 0;
  unsigned int llvm_cbe_puts17;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts18_count = 0;
  unsigned int llvm_cbe_puts18;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts19_count = 0;
  unsigned int llvm_cbe_puts19;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts20_count = 0;
  unsigned int llvm_cbe_puts20;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge148_count = 0;
  unsigned int llvm_cbe_storemerge148;
  unsigned int llvm_cbe_storemerge148__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
  unsigned int llvm_cbe_tmp__138;
  unsigned int llvm_cbe_tmp__138__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  unsigned int llvm_cbe_tmp__139;
  unsigned int llvm_cbe_tmp__139__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  unsigned int llvm_cbe_tmp__140;
  unsigned int llvm_cbe_tmp__140__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;
  static  unsigned long long aesl_llvm_cbe_624_count = 0;
  unsigned long long llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_625_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge744_count = 0;
  unsigned int llvm_cbe_storemerge744;
  unsigned int llvm_cbe_storemerge744__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  unsigned int llvm_cbe_tmp__142;
  unsigned int llvm_cbe_tmp__142__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
  unsigned int llvm_cbe_tmp__143;
  unsigned int llvm_cbe_tmp__143__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
  unsigned int llvm_cbe_tmp__144;
  unsigned int llvm_cbe_tmp__144__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  unsigned long long llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
   char *llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
  unsigned char llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
   char *llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;
  unsigned char llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  unsigned int llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;
  static  unsigned long long aesl_llvm_cbe_645_count = 0;
  static  unsigned long long aesl_llvm_cbe_646_count = 0;
  static  unsigned long long aesl_llvm_cbe_647_count = 0;
  static  unsigned long long aesl_llvm_cbe_648_count = 0;
  static  unsigned long long aesl_llvm_cbe_649_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge7_2e__count = 0;
  unsigned int llvm_cbe_storemerge7_2e_;
  static  unsigned long long aesl_llvm_cbe_storemerge1_2e__count = 0;
  unsigned int llvm_cbe_storemerge1_2e_;
  static  unsigned long long aesl_llvm_cbe_650_count = 0;
  static  unsigned long long aesl_llvm_cbe_651_count = 0;
  unsigned int llvm_cbe_tmp__151;
  unsigned int llvm_cbe_tmp__151__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_652_count = 0;
  unsigned int llvm_cbe_tmp__152;
  unsigned int llvm_cbe_tmp__152__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_653_count = 0;
  unsigned int llvm_cbe_tmp__153;
  unsigned int llvm_cbe_tmp__153__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_654_count = 0;
  unsigned int llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_655_count = 0;
  static  unsigned long long aesl_llvm_cbe_656_count = 0;
  static  unsigned long long aesl_llvm_cbe_657_count = 0;
  static  unsigned long long aesl_llvm_cbe_658_count = 0;
  static  unsigned long long aesl_llvm_cbe_659_count = 0;
  static  unsigned long long aesl_llvm_cbe_660_count = 0;
  static  unsigned long long aesl_llvm_cbe_661_count = 0;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
  static  unsigned long long aesl_llvm_cbe_664_count = 0;
  static  unsigned long long aesl_llvm_cbe_665_count = 0;
  static  unsigned long long aesl_llvm_cbe_666_count = 0;
  static  unsigned long long aesl_llvm_cbe_667_count = 0;
  static  unsigned long long aesl_llvm_cbe_668_count = 0;
  static  unsigned long long aesl_llvm_cbe_669_count = 0;
  static  unsigned long long aesl_llvm_cbe_670_count = 0;
  static  unsigned long long aesl_llvm_cbe_671_count = 0;
  static  unsigned long long aesl_llvm_cbe_672_count = 0;
  static  unsigned long long aesl_llvm_cbe_673_count = 0;
  static  unsigned long long aesl_llvm_cbe_674_count = 0;
  static  unsigned long long aesl_llvm_cbe_675_count = 0;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;
  static  unsigned long long aesl_llvm_cbe_681_count = 0;
  static  unsigned long long aesl_llvm_cbe_682_count = 0;
  static  unsigned long long aesl_llvm_cbe_683_count = 0;
  static  unsigned long long aesl_llvm_cbe_684_count = 0;
  static  unsigned long long aesl_llvm_cbe_685_count = 0;
  static  unsigned long long aesl_llvm_cbe_686_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond63_count = 0;
  static  unsigned long long aesl_llvm_cbe_687_count = 0;
  static  unsigned long long aesl_llvm_cbe_688_count = 0;
  unsigned int llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_689_count = 0;
  static  unsigned long long aesl_llvm_cbe_690_count = 0;
  static  unsigned long long aesl_llvm_cbe_691_count = 0;
  static  unsigned long long aesl_llvm_cbe_692_count = 0;
  static  unsigned long long aesl_llvm_cbe_693_count = 0;
  static  unsigned long long aesl_llvm_cbe_694_count = 0;
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
  static  unsigned long long aesl_llvm_cbe_714_count = 0;
  static  unsigned long long aesl_llvm_cbe_715_count = 0;
  static  unsigned long long aesl_llvm_cbe_716_count = 0;
  static  unsigned long long aesl_llvm_cbe_717_count = 0;
  static  unsigned long long aesl_llvm_cbe_718_count = 0;
  static  unsigned long long aesl_llvm_cbe_719_count = 0;
  static  unsigned long long aesl_llvm_cbe_720_count = 0;
  static  unsigned long long aesl_llvm_cbe_721_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond64_count = 0;
  static  unsigned long long aesl_llvm_cbe_722_count = 0;
  static  unsigned long long aesl_llvm_cbe_723_count = 0;
  static  unsigned long long aesl_llvm_cbe_724_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts21_count = 0;
  unsigned int llvm_cbe_puts21;
  static  unsigned long long aesl_llvm_cbe_725_count = 0;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  unsigned int llvm_cbe_tmp__156;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  unsigned long long llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  unsigned long long llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
   char *llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  unsigned char llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  unsigned int llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
   char *llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  unsigned char llvm_cbe_tmp__163;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  unsigned int llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  unsigned int llvm_cbe_tmp__165;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts22_count = 0;
  unsigned int llvm_cbe_puts22;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  static  unsigned long long aesl_llvm_cbe_761_count = 0;
  static  unsigned long long aesl_llvm_cbe_762_count = 0;
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge239_count = 0;
  unsigned int llvm_cbe_storemerge239;
  unsigned int llvm_cbe_storemerge239__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
  static  unsigned long long aesl_llvm_cbe_787_count = 0;
  static  unsigned long long aesl_llvm_cbe_788_count = 0;
  unsigned long long llvm_cbe_tmp__166;
  static  unsigned long long aesl_llvm_cbe_789_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge638_count = 0;
  unsigned int llvm_cbe_storemerge638;
  unsigned int llvm_cbe_storemerge638__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_790_count = 0;
  unsigned int llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;
  unsigned int llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_792_count = 0;
  static  unsigned long long aesl_llvm_cbe_793_count = 0;
  static  unsigned long long aesl_llvm_cbe_794_count = 0;
  unsigned long long llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_795_count = 0;
   char *llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_796_count = 0;
  static  unsigned long long aesl_llvm_cbe_797_count = 0;
   char *llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  unsigned long long llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
   char *llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
   char *llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  unsigned long long llvm_cbe_tmp__175;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
   char *llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  static  unsigned long long aesl_llvm_cbe_811_count = 0;
   char *llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_812_count = 0;
  static  unsigned long long aesl_llvm_cbe_813_count = 0;
  static  unsigned long long aesl_llvm_cbe_814_count = 0;
  static  unsigned long long aesl_llvm_cbe_815_count = 0;
  unsigned int llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_816_count = 0;
  static  unsigned long long aesl_llvm_cbe_817_count = 0;
  static  unsigned long long aesl_llvm_cbe_818_count = 0;
  static  unsigned long long aesl_llvm_cbe_819_count = 0;
  static  unsigned long long aesl_llvm_cbe_820_count = 0;
  static  unsigned long long aesl_llvm_cbe_821_count = 0;
  static  unsigned long long aesl_llvm_cbe_822_count = 0;
  static  unsigned long long aesl_llvm_cbe_823_count = 0;
  static  unsigned long long aesl_llvm_cbe_824_count = 0;
  static  unsigned long long aesl_llvm_cbe_825_count = 0;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  static  unsigned long long aesl_llvm_cbe_830_count = 0;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;
  static  unsigned long long aesl_llvm_cbe_836_count = 0;
  static  unsigned long long aesl_llvm_cbe_837_count = 0;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond59_count = 0;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
  unsigned int llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_843_count = 0;
  static  unsigned long long aesl_llvm_cbe_844_count = 0;
  static  unsigned long long aesl_llvm_cbe_845_count = 0;
  static  unsigned long long aesl_llvm_cbe_846_count = 0;
  static  unsigned long long aesl_llvm_cbe_847_count = 0;
  static  unsigned long long aesl_llvm_cbe_848_count = 0;
  static  unsigned long long aesl_llvm_cbe_849_count = 0;
  static  unsigned long long aesl_llvm_cbe_850_count = 0;
  static  unsigned long long aesl_llvm_cbe_851_count = 0;
  static  unsigned long long aesl_llvm_cbe_852_count = 0;
  static  unsigned long long aesl_llvm_cbe_853_count = 0;
  static  unsigned long long aesl_llvm_cbe_854_count = 0;
  static  unsigned long long aesl_llvm_cbe_855_count = 0;
  static  unsigned long long aesl_llvm_cbe_856_count = 0;
  static  unsigned long long aesl_llvm_cbe_857_count = 0;
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  static  unsigned long long aesl_llvm_cbe_859_count = 0;
  static  unsigned long long aesl_llvm_cbe_860_count = 0;
  static  unsigned long long aesl_llvm_cbe_861_count = 0;
  static  unsigned long long aesl_llvm_cbe_862_count = 0;
  static  unsigned long long aesl_llvm_cbe_863_count = 0;
  static  unsigned long long aesl_llvm_cbe_864_count = 0;
  static  unsigned long long aesl_llvm_cbe_865_count = 0;
  static  unsigned long long aesl_llvm_cbe_866_count = 0;
  static  unsigned long long aesl_llvm_cbe_867_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond60_count = 0;
  static  unsigned long long aesl_llvm_cbe_868_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts23_count = 0;
  unsigned int llvm_cbe_puts23;
  static  unsigned long long aesl_llvm_cbe_869_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts24_count = 0;
  unsigned int llvm_cbe_puts24;
  static  unsigned long long aesl_llvm_cbe_870_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts25_count = 0;
  unsigned int llvm_cbe_puts25;
  static  unsigned long long aesl_llvm_cbe_871_count = 0;
  static  unsigned long long aesl_llvm_cbe_872_count = 0;
  static  unsigned long long aesl_llvm_cbe_873_count = 0;
  static  unsigned long long aesl_llvm_cbe_874_count = 0;
  static  unsigned long long aesl_llvm_cbe_875_count = 0;
  static  unsigned long long aesl_llvm_cbe_876_count = 0;
  static  unsigned long long aesl_llvm_cbe_877_count = 0;
  static  unsigned long long aesl_llvm_cbe_878_count = 0;
  static  unsigned long long aesl_llvm_cbe_879_count = 0;
  static  unsigned long long aesl_llvm_cbe_880_count = 0;
  static  unsigned long long aesl_llvm_cbe_881_count = 0;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
  static  unsigned long long aesl_llvm_cbe_885_count = 0;
  static  unsigned long long aesl_llvm_cbe_886_count = 0;
  static  unsigned long long aesl_llvm_cbe_887_count = 0;
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
  static  unsigned long long aesl_llvm_cbe_893_count = 0;
  static  unsigned long long aesl_llvm_cbe_894_count = 0;
  static  unsigned long long aesl_llvm_cbe_895_count = 0;
  static  unsigned long long aesl_llvm_cbe_896_count = 0;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
  static  unsigned long long aesl_llvm_cbe_903_count = 0;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;
  static  unsigned long long aesl_llvm_cbe_908_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge336_count = 0;
  unsigned int llvm_cbe_storemerge336;
  unsigned int llvm_cbe_storemerge336__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_909_count = 0;
  unsigned int llvm_cbe_tmp__180;
  unsigned int llvm_cbe_tmp__180__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_910_count = 0;
  static  unsigned long long aesl_llvm_cbe_911_count = 0;
  static  unsigned long long aesl_llvm_cbe_912_count = 0;
  static  unsigned long long aesl_llvm_cbe_913_count = 0;
  static  unsigned long long aesl_llvm_cbe_914_count = 0;
  static  unsigned long long aesl_llvm_cbe_915_count = 0;
  static  unsigned long long aesl_llvm_cbe_916_count = 0;
  static  unsigned long long aesl_llvm_cbe_917_count = 0;
  static  unsigned long long aesl_llvm_cbe_918_count = 0;
  static  unsigned long long aesl_llvm_cbe_919_count = 0;
  static  unsigned long long aesl_llvm_cbe_920_count = 0;
  static  unsigned long long aesl_llvm_cbe_921_count = 0;
  static  unsigned long long aesl_llvm_cbe_922_count = 0;
  static  unsigned long long aesl_llvm_cbe_923_count = 0;
  static  unsigned long long aesl_llvm_cbe_924_count = 0;
  static  unsigned long long aesl_llvm_cbe_925_count = 0;
  static  unsigned long long aesl_llvm_cbe_926_count = 0;
  static  unsigned long long aesl_llvm_cbe_927_count = 0;
  static  unsigned long long aesl_llvm_cbe_928_count = 0;
  static  unsigned long long aesl_llvm_cbe_929_count = 0;
  static  unsigned long long aesl_llvm_cbe_930_count = 0;
  static  unsigned long long aesl_llvm_cbe_931_count = 0;
  static  unsigned long long aesl_llvm_cbe_932_count = 0;
  static  unsigned long long aesl_llvm_cbe_933_count = 0;
  static  unsigned long long aesl_llvm_cbe_934_count = 0;
  unsigned long long llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_935_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge534_count = 0;
  unsigned int llvm_cbe_storemerge534;
  unsigned int llvm_cbe_storemerge534__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_936_count = 0;
  unsigned int llvm_cbe_tmp__182;
  unsigned int llvm_cbe_tmp__182__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_937_count = 0;
  unsigned long long llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_938_count = 0;
   char *llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_939_count = 0;
  unsigned char llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_940_count = 0;
   char *llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_941_count = 0;
  unsigned char llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  unsigned int llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;
  static  unsigned long long aesl_llvm_cbe_945_count = 0;
  static  unsigned long long aesl_llvm_cbe_946_count = 0;
  static  unsigned long long aesl_llvm_cbe_947_count = 0;
  static  unsigned long long aesl_llvm_cbe_948_count = 0;
  static  unsigned long long aesl_llvm_cbe_949_count = 0;
  static  unsigned long long aesl_llvm_cbe_950_count = 0;
  static  unsigned long long aesl_llvm_cbe_951_count = 0;
  static  unsigned long long aesl_llvm_cbe_952_count = 0;
  static  unsigned long long aesl_llvm_cbe_953_count = 0;
  static  unsigned long long aesl_llvm_cbe_954_count = 0;
  static  unsigned long long aesl_llvm_cbe_955_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_956_count = 0;
  unsigned int llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_957_count = 0;
  static  unsigned long long aesl_llvm_cbe_958_count = 0;
  static  unsigned long long aesl_llvm_cbe_959_count = 0;
  static  unsigned long long aesl_llvm_cbe_960_count = 0;
  static  unsigned long long aesl_llvm_cbe_961_count = 0;
  static  unsigned long long aesl_llvm_cbe_962_count = 0;
  static  unsigned long long aesl_llvm_cbe_963_count = 0;
  static  unsigned long long aesl_llvm_cbe_964_count = 0;
  static  unsigned long long aesl_llvm_cbe_965_count = 0;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;
  static  unsigned long long aesl_llvm_cbe_980_count = 0;
  static  unsigned long long aesl_llvm_cbe_981_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
  unsigned int llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
  static  unsigned long long aesl_llvm_cbe_1007_count = 0;
  static  unsigned long long aesl_llvm_cbe_1008_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond58_count = 0;
  static  unsigned long long aesl_llvm_cbe_1009_count = 0;
  static  unsigned long long aesl_llvm_cbe_1010_count = 0;
  static  unsigned long long aesl_llvm_cbe_1011_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts26_count = 0;
  unsigned int llvm_cbe_puts26;
  static  unsigned long long aesl_llvm_cbe_1012_count = 0;
  static  unsigned long long aesl_llvm_cbe_1013_count = 0;
  unsigned int llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_1014_count = 0;
  static  unsigned long long aesl_llvm_cbe_1015_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts27_count = 0;
  unsigned int llvm_cbe_puts27;
  static  unsigned long long aesl_llvm_cbe_puts28_count = 0;
  unsigned int llvm_cbe_puts28;
  static  unsigned long long aesl_llvm_cbe_puts29_count = 0;
  unsigned int llvm_cbe_puts29;
  static  unsigned long long aesl_llvm_cbe_1016_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts30_count = 0;
  unsigned int llvm_cbe_puts30;
  static  unsigned long long aesl_llvm_cbe_puts31_count = 0;
  unsigned int llvm_cbe_puts31;
  static  unsigned long long aesl_llvm_cbe_1017_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts32_count = 0;
  unsigned int llvm_cbe_puts32;
  static  unsigned long long aesl_llvm_cbe_puts33_count = 0;
  unsigned int llvm_cbe_puts33;
  static  unsigned long long aesl_llvm_cbe_1018_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge4_count = 0;
  unsigned int llvm_cbe_storemerge4;
  unsigned int llvm_cbe_storemerge4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1019_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = tail call i32 @puts(i8* getelementptr inbounds ([50 x i8]* @aesl_internal_str22, i64 0, i64 0)), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts_count);
   /*tail*/ puts(( char *)((&aesl_internal_str22[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 50
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts9 = tail call i32 @puts(i8* getelementptr inbounds ([31 x i8]* @aesl_internal_str2, i64 0, i64 0)), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts9_count);
   /*tail*/ puts(( char *)((&aesl_internal_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 31
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts9 = 0x%X",llvm_cbe_puts9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts10 = tail call i32 @puts(i8* getelementptr inbounds ([50 x i8]* @aesl_internal_str22, i64 0, i64 0)), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts10_count);
   /*tail*/ puts(( char *)((&aesl_internal_str22[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 50
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts10 = 0x%X",llvm_cbe_puts10);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([21 x i8]* @aesl_internal_.str10, i64 0, i64 0), i32 256, i32 256) nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_322_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 21
#endif
])), 256u, 256u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",256u);
printf("\nArgument  = 0x%X",256u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__108);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([30 x i8]* @aesl_internal_.str11, i64 0, i64 0), i32 32, i32 96) nounwind, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_323_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str11[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), 32u, 96u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",32u);
printf("\nArgument  = 0x%X",96u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__109);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts11 = tail call i32 @puts(i8* getelementptr inbounds ([50 x i8]* @aesl_internal_str22, i64 0, i64 0)), !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts11_count);
   /*tail*/ puts(( char *)((&aesl_internal_str22[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 50
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts11 = 0x%X",llvm_cbe_puts11);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts12 = tail call i32 @puts(i8* getelementptr inbounds ([40 x i8]* @aesl_internal_str5, i64 0, i64 0)), !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts12_count);
   /*tail*/ puts(( char *)((&aesl_internal_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 40
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts12 = 0x%X",llvm_cbe_puts12);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @init_gradient_image([256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.A, i64 0, i64 0), i32 0, i32 1), !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_324_count);
   /*tail*/ init_gradient_image(((&aesl_internal_main_OC_A[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), 0u, 1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%X",1u);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @init_gradient_image([256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.B, i64 0, i64 0), i32 50, i32 1), !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_325_count);
   /*tail*/ init_gradient_image(((&aesl_internal_main_OC_B[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), 50u, 1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",50u);
printf("\nArgument  = 0x%X",1u);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @print_image_subset([256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.A, i64 0, i64 0), i32 8, i32 8, i8* getelementptr inbounds ([8 x i8]* @aesl_internal_.str13, i64 0, i64 0)), !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_326_count);
   /*tail*/ print_image_subset(((&aesl_internal_main_OC_A[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), 8u, 8u, ( char *)((&aesl_internal__OC_str13[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",8u);
printf("\nArgument  = 0x%X",8u);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @print_image_subset([256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.B, i64 0, i64 0), i32 8, i32 8, i8* getelementptr inbounds ([8 x i8]* @aesl_internal_.str14, i64 0, i64 0)), !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_327_count);
   /*tail*/ print_image_subset(((&aesl_internal_main_OC_B[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), 8u, 8u, ( char *)((&aesl_internal__OC_str14[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",8u);
printf("\nArgument  = 0x%X",8u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts13 = tail call i32 @puts(i8* getelementptr inbounds ([31 x i8]* @aesl_internal_str16, i64 0, i64 0)), !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts13_count);
   /*tail*/ puts(( char *)((&aesl_internal_str16[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 31
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts13 = 0x%X",llvm_cbe_puts13);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @image_diff_posterize_sw_ref([256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.A, i64 0, i64 0), [256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.B, i64 0, i64 0), [256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.C_sw, i64 0, i64 0)), !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_328_count);
   /*tail*/ image_diff_posterize_sw_ref(((&aesl_internal_main_OC_A[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), ((&aesl_internal_main_OC_B[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), ((&aesl_internal_main_OC_C_sw[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts14 = tail call i32 @puts(i8* getelementptr inbounds ([32 x i8]* @aesl_internal_str17, i64 0, i64 0)), !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts14_count);
   /*tail*/ puts(( char *)((&aesl_internal_str17[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts14 = 0x%X",llvm_cbe_puts14);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @apatb_image_diff_posterize_sw([256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.A, i64 0, i64 0), [256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.B, i64 0, i64 0), [256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.C_hw, i64 0, i64 0)) nounwind, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_329_count);
   /*tail*/ apatb_image_diff_posterize_sw(((&aesl_internal_main_OC_A[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), ((&aesl_internal_main_OC_B[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), ((&aesl_internal_main_OC_C_hw[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts15 = tail call i32 @puts(i8* getelementptr inbounds ([22 x i8]* @aesl_internal_str18, i64 0, i64 0)), !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts15_count);
   /*tail*/ puts(( char *)((&aesl_internal_str18[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 22
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts15 = 0x%X",llvm_cbe_puts15);
}
  llvm_cbe_storemerge57__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__110__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__111__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
  llvm_cbe_tmp__112__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
  goto llvm_cbe__2e_preheader49;

  do {     /* Syntactic loop '.preheader49' to make GCC happy */
llvm_cbe__2e_preheader49:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge57 = phi i32 [ 0, %%0 ], [ %%26, %%25  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge57_count);
  llvm_cbe_storemerge57 = (unsigned int )llvm_cbe_storemerge57__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge57 = 0x%X",llvm_cbe_storemerge57);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__127);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = phi i32 [ 0, %%0 ], [ %%23, %%25  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_391_count);
  llvm_cbe_tmp__110 = (unsigned int )llvm_cbe_tmp__110__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__110);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__125);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = phi i32 [ -1, %%0 ], [ %%22, %%25  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_392_count);
  llvm_cbe_tmp__111 = (unsigned int )llvm_cbe_tmp__111__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__111);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",llvm_cbe_tmp__124);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = phi i32 [ -1, %%0 ], [ %%21, %%25  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_393_count);
  llvm_cbe_tmp__112 = (unsigned int )llvm_cbe_tmp__112__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__112);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",llvm_cbe_tmp__123);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sext i32 %%storemerge57 to i64, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_425_count);
  llvm_cbe_tmp__113 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge57);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__113);
  llvm_cbe_storemerge853__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__114__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__110;   /* for PHI node */
  llvm_cbe_tmp__115__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__111;   /* for PHI node */
  llvm_cbe_tmp__116__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__112;   /* for PHI node */
  goto llvm_cbe_tmp__192;

llvm_cbe_tmp__193:
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add nsw i32 %%storemerge57, 1, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_489_count);
  llvm_cbe_tmp__127 = (unsigned int )((unsigned int )(llvm_cbe_storemerge57&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__127&4294967295ull)));
  if (((llvm_cbe_tmp__127&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__194;
  } else {
    llvm_cbe_storemerge57__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__127;   /* for PHI node */
    llvm_cbe_tmp__110__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__125;   /* for PHI node */
    llvm_cbe_tmp__111__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__124;   /* for PHI node */
    llvm_cbe_tmp__112__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__123;   /* for PHI node */
    goto llvm_cbe__2e_preheader49;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__192:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge853 = phi i32 [ 0, %%.preheader49 ], [ %%24, %%20  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge853_count);
  llvm_cbe_storemerge853 = (unsigned int )llvm_cbe_storemerge853__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge853 = 0x%X",llvm_cbe_storemerge853);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__126);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = phi i32 [ %%3, %%.preheader49 ], [ %%23, %%20  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_427_count);
  llvm_cbe_tmp__114 = (unsigned int )llvm_cbe_tmp__114__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__114);
printf("\n = 0x%X",llvm_cbe_tmp__110);
printf("\n = 0x%X",llvm_cbe_tmp__125);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = phi i32 [ %%4, %%.preheader49 ], [ %%22, %%20  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_428_count);
  llvm_cbe_tmp__115 = (unsigned int )llvm_cbe_tmp__115__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__115);
printf("\n = 0x%X",llvm_cbe_tmp__111);
printf("\n = 0x%X",llvm_cbe_tmp__124);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = phi i32 [ %%5, %%.preheader49 ], [ %%21, %%20  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_429_count);
  llvm_cbe_tmp__116 = (unsigned int )llvm_cbe_tmp__116__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__116);
printf("\n = 0x%X",llvm_cbe_tmp__112);
printf("\n = 0x%X",llvm_cbe_tmp__123);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%storemerge853 to i64, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_430_count);
  llvm_cbe_tmp__117 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge853);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__117);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [256 x [256 x i8]]* @aesl_internal_main.C_hw, i64 0, i64 %%6, i64 %%11, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_431_count);
  llvm_cbe_tmp__118 = ( char *)(&aesl_internal_main_OC_C_hw[(((signed long long )llvm_cbe_tmp__113))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__117))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__113));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__117));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__113) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_hw' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__117) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_hw' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i8* %%12, align 1, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_432_count);
  llvm_cbe_tmp__119 = (unsigned char )*llvm_cbe_tmp__118;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__119);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds [256 x [256 x i8]]* @aesl_internal_main.C_sw, i64 0, i64 %%6, i64 %%11, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_433_count);
  llvm_cbe_tmp__120 = ( char *)(&aesl_internal_main_OC_C_sw[(((signed long long )llvm_cbe_tmp__113))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__117))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__113));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__117));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__113) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_sw' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__117) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_sw' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i8* %%14, align 1, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_434_count);
  llvm_cbe_tmp__121 = (unsigned char )*llvm_cbe_tmp__120;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__121);
  if (((llvm_cbe_tmp__119&255U) == (llvm_cbe_tmp__121&255U))) {
    llvm_cbe_tmp__123__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__116;   /* for PHI node */
    llvm_cbe_tmp__124__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__115;   /* for PHI node */
    llvm_cbe_tmp__125__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__114;   /* for PHI node */
    goto llvm_cbe_tmp__195;
  } else {
    goto llvm_cbe_tmp__196;
  }

llvm_cbe_tmp__195:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = phi i32 [ %%10, %%7 ], [ %%storemerge8., %%17  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_452_count);
  llvm_cbe_tmp__123 = (unsigned int )llvm_cbe_tmp__123__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__123);
printf("\n = 0x%X",llvm_cbe_tmp__116);
printf("\nstoremerge8. = 0x%X",llvm_cbe_storemerge8_2e_);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = phi i32 [ %%9, %%7 ], [ %%storemerge., %%17  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_453_count);
  llvm_cbe_tmp__124 = (unsigned int )llvm_cbe_tmp__124__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__124);
printf("\n = 0x%X",llvm_cbe_tmp__115);
printf("\nstoremerge. = 0x%X",llvm_cbe_storemerge_2e_);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = phi i32 [ %%8, %%7 ], [ %%18, %%17  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_454_count);
  llvm_cbe_tmp__125 = (unsigned int )llvm_cbe_tmp__125__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__125);
printf("\n = 0x%X",llvm_cbe_tmp__114);
printf("\n = 0x%X",llvm_cbe_tmp__122);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add nsw i32 %%storemerge853, 1, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_455_count);
  llvm_cbe_tmp__126 = (unsigned int )((unsigned int )(llvm_cbe_storemerge853&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__126&4294967295ull)));
  if (((llvm_cbe_tmp__126&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__193;
  } else {
    llvm_cbe_storemerge853__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__126;   /* for PHI node */
    llvm_cbe_tmp__114__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__125;   /* for PHI node */
    llvm_cbe_tmp__115__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__124;   /* for PHI node */
    llvm_cbe_tmp__116__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__123;   /* for PHI node */
    goto llvm_cbe_tmp__192;
  }

llvm_cbe_tmp__196:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%8, 1, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_437_count);
  llvm_cbe_tmp__122 = (unsigned int )((unsigned int )(llvm_cbe_tmp__114&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__122&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8. = select i1 %%19, i32 %%storemerge853, i32 %%10, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge8_2e__count);
  llvm_cbe_storemerge8_2e_ = (unsigned int )((((llvm_cbe_tmp__115&4294967295U) == (4294967295u&4294967295U))) ? ((unsigned int )llvm_cbe_storemerge853) : ((unsigned int )llvm_cbe_tmp__116));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge8. = 0x%X\n", llvm_cbe_storemerge8_2e_);
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge. = select i1 %%19, i32 %%storemerge57, i32 %%9, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge_2e__count);
  llvm_cbe_storemerge_2e_ = (unsigned int )((((llvm_cbe_tmp__115&4294967295U) == (4294967295u&4294967295U))) ? ((unsigned int )llvm_cbe_storemerge57) : ((unsigned int )llvm_cbe_tmp__115));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge. = 0x%X\n", llvm_cbe_storemerge_2e_);
  llvm_cbe_tmp__123__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge8_2e_;   /* for PHI node */
  llvm_cbe_tmp__124__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge_2e_;   /* for PHI node */
  llvm_cbe_tmp__125__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__122;   /* for PHI node */
  goto llvm_cbe_tmp__195;

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader49' */
llvm_cbe_tmp__194:
  if (((llvm_cbe_tmp__125&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__197;
  } else {
    goto llvm_cbe_tmp__198;
  }

llvm_cbe_tmp__197:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts16 = tail call i32 @puts(i8* getelementptr inbounds ([27 x i8]* @aesl_internal_str9, i64 0, i64 0)), !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts16_count);
   /*tail*/ puts(( char *)((&aesl_internal_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 27
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts16 = 0x%X",llvm_cbe_puts16);
}
  goto llvm_cbe_tmp__199;

llvm_cbe_tmp__198:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str19, i64 0, i64 0), i32 %%23) nounwind, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_527_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str19[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), llvm_cbe_tmp__125);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__125);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__128);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = sext i32 %%21 to i64, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_528_count);
  llvm_cbe_tmp__129 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__129);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = sext i32 %%22 to i64, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_529_count);
  llvm_cbe_tmp__130 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__124);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__130);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds [256 x [256 x i8]]* @aesl_internal_main.C_hw, i64 0, i64 %%33, i64 %%32, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_530_count);
  llvm_cbe_tmp__131 = ( char *)(&aesl_internal_main_OC_C_hw[(((signed long long )llvm_cbe_tmp__130))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__129))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__130));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__129));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__130) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_hw' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__129) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_hw' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i8* %%34, align 1, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_531_count);
  llvm_cbe_tmp__132 = (unsigned char )*llvm_cbe_tmp__131;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__132);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = zext i8 %%35 to i32, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_532_count);
  llvm_cbe_tmp__133 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__132&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__133);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds [256 x [256 x i8]]* @aesl_internal_main.C_sw, i64 0, i64 %%33, i64 %%32, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_533_count);
  llvm_cbe_tmp__134 = ( char *)(&aesl_internal_main_OC_C_sw[(((signed long long )llvm_cbe_tmp__130))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__129))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__130));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__129));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__130) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_sw' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__129) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_sw' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i8* %%37, align 1, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_534_count);
  llvm_cbe_tmp__135 = (unsigned char )*llvm_cbe_tmp__134;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__135);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = zext i8 %%38 to i32, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_535_count);
  llvm_cbe_tmp__136 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__135&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__136);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([41 x i8]* @aesl_internal_.str20, i64 0, i64 0), i32 %%22, i32 %%21, i32 %%36, i32 %%39) nounwind, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_536_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str20[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 41
#endif
])), llvm_cbe_tmp__124, llvm_cbe_tmp__123, llvm_cbe_tmp__133, llvm_cbe_tmp__136);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__124);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__123);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__133);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__136);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__137);
}
  goto llvm_cbe_tmp__199;

llvm_cbe_tmp__199:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @print_image_subset([256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.C_hw, i64 0, i64 0), i32 8, i32 8, i8* getelementptr inbounds ([26 x i8]* @aesl_internal_.str21, i64 0, i64 0)), !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_538_count);
   /*tail*/ print_image_subset(((&aesl_internal_main_OC_C_hw[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), 8u, 8u, ( char *)((&aesl_internal__OC_str21[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 26
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",8u);
printf("\nArgument  = 0x%X",8u);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @calculate_statistics([256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.C_hw, i64 0, i64 0)), !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_539_count);
   /*tail*/ calculate_statistics(((&aesl_internal_main_OC_C_hw[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts17 = tail call i32 @puts(i8* getelementptr inbounds ([36 x i8]* @aesl_internal_str10, i64 0, i64 0)), !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts17_count);
   /*tail*/ puts(( char *)((&aesl_internal_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 36
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts17 = 0x%X",llvm_cbe_puts17);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @init_random_image([256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.A, i64 0, i64 0), i32 12345), !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_540_count);
   /*tail*/ init_random_image(((&aesl_internal_main_OC_A[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), 12345u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",12345u);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @init_random_image([256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.B, i64 0, i64 0), i32 67890), !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_541_count);
   /*tail*/ init_random_image(((&aesl_internal_main_OC_B[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), 67890u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",67890u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts18 = tail call i32 @puts(i8* getelementptr inbounds ([31 x i8]* @aesl_internal_str16, i64 0, i64 0)), !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts18_count);
   /*tail*/ puts(( char *)((&aesl_internal_str16[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 31
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts18 = 0x%X",llvm_cbe_puts18);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @image_diff_posterize_sw_ref([256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.A, i64 0, i64 0), [256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.B, i64 0, i64 0), [256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.C_sw, i64 0, i64 0)), !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_542_count);
   /*tail*/ image_diff_posterize_sw_ref(((&aesl_internal_main_OC_A[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), ((&aesl_internal_main_OC_B[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), ((&aesl_internal_main_OC_C_sw[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts19 = tail call i32 @puts(i8* getelementptr inbounds ([32 x i8]* @aesl_internal_str17, i64 0, i64 0)), !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts19_count);
   /*tail*/ puts(( char *)((&aesl_internal_str17[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts19 = 0x%X",llvm_cbe_puts19);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @apatb_image_diff_posterize_sw([256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.A, i64 0, i64 0), [256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.B, i64 0, i64 0), [256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.C_hw, i64 0, i64 0)) nounwind, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_543_count);
   /*tail*/ apatb_image_diff_posterize_sw(((&aesl_internal_main_OC_A[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), ((&aesl_internal_main_OC_B[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), ((&aesl_internal_main_OC_C_hw[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts20 = tail call i32 @puts(i8* getelementptr inbounds ([22 x i8]* @aesl_internal_str18, i64 0, i64 0)), !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts20_count);
   /*tail*/ puts(( char *)((&aesl_internal_str18[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 22
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts20 = 0x%X",llvm_cbe_puts20);
}
  llvm_cbe_storemerge148__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__138__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__139__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__124;   /* for PHI node */
  llvm_cbe_tmp__140__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__123;   /* for PHI node */
  goto llvm_cbe__2e_preheader40;

  do {     /* Syntactic loop '.preheader40' to make GCC happy */
llvm_cbe__2e_preheader40:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge148 = phi i32 [ 0, %%41 ], [ %%65, %%64  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge148_count);
  llvm_cbe_storemerge148 = (unsigned int )llvm_cbe_storemerge148__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge148 = 0x%X",llvm_cbe_storemerge148);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__155);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = phi i32 [ 0, %%41 ], [ %%62, %%64  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_590_count);
  llvm_cbe_tmp__138 = (unsigned int )llvm_cbe_tmp__138__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__138);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__153);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = phi i32 [ %%22, %%41 ], [ %%61, %%64  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_591_count);
  llvm_cbe_tmp__139 = (unsigned int )llvm_cbe_tmp__139__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__139);
printf("\n = 0x%X",llvm_cbe_tmp__124);
printf("\n = 0x%X",llvm_cbe_tmp__152);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = phi i32 [ %%21, %%41 ], [ %%60, %%64  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_592_count);
  llvm_cbe_tmp__140 = (unsigned int )llvm_cbe_tmp__140__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__140);
printf("\n = 0x%X",llvm_cbe_tmp__123);
printf("\n = 0x%X",llvm_cbe_tmp__151);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = sext i32 %%storemerge148 to i64, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_624_count);
  llvm_cbe_tmp__141 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge148);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__141);
  llvm_cbe_storemerge744__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__142__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__138;   /* for PHI node */
  llvm_cbe_tmp__143__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__139;   /* for PHI node */
  llvm_cbe_tmp__144__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__140;   /* for PHI node */
  goto llvm_cbe_tmp__200;

llvm_cbe_tmp__201:
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = add nsw i32 %%storemerge148, 1, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_688_count);
  llvm_cbe_tmp__155 = (unsigned int )((unsigned int )(llvm_cbe_storemerge148&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__155&4294967295ull)));
  if (((llvm_cbe_tmp__155&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__202;
  } else {
    llvm_cbe_storemerge148__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__155;   /* for PHI node */
    llvm_cbe_tmp__138__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__153;   /* for PHI node */
    llvm_cbe_tmp__139__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__152;   /* for PHI node */
    llvm_cbe_tmp__140__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__151;   /* for PHI node */
    goto llvm_cbe__2e_preheader40;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__200:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge744 = phi i32 [ 0, %%.preheader40 ], [ %%63, %%59  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge744_count);
  llvm_cbe_storemerge744 = (unsigned int )llvm_cbe_storemerge744__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge744 = 0x%X",llvm_cbe_storemerge744);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__154);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = phi i32 [ %%42, %%.preheader40 ], [ %%62, %%59  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_626_count);
  llvm_cbe_tmp__142 = (unsigned int )llvm_cbe_tmp__142__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__142);
printf("\n = 0x%X",llvm_cbe_tmp__138);
printf("\n = 0x%X",llvm_cbe_tmp__153);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = phi i32 [ %%43, %%.preheader40 ], [ %%61, %%59  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_627_count);
  llvm_cbe_tmp__143 = (unsigned int )llvm_cbe_tmp__143__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__143);
printf("\n = 0x%X",llvm_cbe_tmp__139);
printf("\n = 0x%X",llvm_cbe_tmp__152);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = phi i32 [ %%44, %%.preheader40 ], [ %%60, %%59  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_628_count);
  llvm_cbe_tmp__144 = (unsigned int )llvm_cbe_tmp__144__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__144);
printf("\n = 0x%X",llvm_cbe_tmp__140);
printf("\n = 0x%X",llvm_cbe_tmp__151);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = sext i32 %%storemerge744 to i64, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_629_count);
  llvm_cbe_tmp__145 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge744);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__145);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds [256 x [256 x i8]]* @aesl_internal_main.C_hw, i64 0, i64 %%45, i64 %%50, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_630_count);
  llvm_cbe_tmp__146 = ( char *)(&aesl_internal_main_OC_C_hw[(((signed long long )llvm_cbe_tmp__141))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__145))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__141));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__145));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__141) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_hw' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__145) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_hw' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load i8* %%51, align 1, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_631_count);
  llvm_cbe_tmp__147 = (unsigned char )*llvm_cbe_tmp__146;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__147);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds [256 x [256 x i8]]* @aesl_internal_main.C_sw, i64 0, i64 %%45, i64 %%50, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_632_count);
  llvm_cbe_tmp__148 = ( char *)(&aesl_internal_main_OC_C_sw[(((signed long long )llvm_cbe_tmp__141))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__145))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__141));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__145));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__141) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_sw' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__145) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_sw' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load i8* %%53, align 1, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_633_count);
  llvm_cbe_tmp__149 = (unsigned char )*llvm_cbe_tmp__148;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__149);
  if (((llvm_cbe_tmp__147&255U) == (llvm_cbe_tmp__149&255U))) {
    llvm_cbe_tmp__151__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__144;   /* for PHI node */
    llvm_cbe_tmp__152__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__143;   /* for PHI node */
    llvm_cbe_tmp__153__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__142;   /* for PHI node */
    goto llvm_cbe_tmp__203;
  } else {
    goto llvm_cbe_tmp__204;
  }

llvm_cbe_tmp__203:
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = phi i32 [ %%49, %%46 ], [ %%storemerge7., %%56  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_651_count);
  llvm_cbe_tmp__151 = (unsigned int )llvm_cbe_tmp__151__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__151);
printf("\n = 0x%X",llvm_cbe_tmp__144);
printf("\nstoremerge7. = 0x%X",llvm_cbe_storemerge7_2e_);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = phi i32 [ %%48, %%46 ], [ %%storemerge1., %%56  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_652_count);
  llvm_cbe_tmp__152 = (unsigned int )llvm_cbe_tmp__152__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__152);
printf("\n = 0x%X",llvm_cbe_tmp__143);
printf("\nstoremerge1. = 0x%X",llvm_cbe_storemerge1_2e_);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = phi i32 [ %%47, %%46 ], [ %%57, %%56  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_653_count);
  llvm_cbe_tmp__153 = (unsigned int )llvm_cbe_tmp__153__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__153);
printf("\n = 0x%X",llvm_cbe_tmp__142);
printf("\n = 0x%X",llvm_cbe_tmp__150);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = add nsw i32 %%storemerge744, 1, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_654_count);
  llvm_cbe_tmp__154 = (unsigned int )((unsigned int )(llvm_cbe_storemerge744&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__154&4294967295ull)));
  if (((llvm_cbe_tmp__154&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__201;
  } else {
    llvm_cbe_storemerge744__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__154;   /* for PHI node */
    llvm_cbe_tmp__142__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__153;   /* for PHI node */
    llvm_cbe_tmp__143__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__152;   /* for PHI node */
    llvm_cbe_tmp__144__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__151;   /* for PHI node */
    goto llvm_cbe_tmp__200;
  }

llvm_cbe_tmp__204:
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = add nsw i32 %%47, 1, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_636_count);
  llvm_cbe_tmp__150 = (unsigned int )((unsigned int )(llvm_cbe_tmp__142&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__150&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7. = select i1 %%58, i32 %%storemerge744, i32 %%49, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge7_2e__count);
  llvm_cbe_storemerge7_2e_ = (unsigned int )((((llvm_cbe_tmp__142&4294967295U) == (0u&4294967295U))) ? ((unsigned int )llvm_cbe_storemerge744) : ((unsigned int )llvm_cbe_tmp__144));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge7. = 0x%X\n", llvm_cbe_storemerge7_2e_);
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1. = select i1 %%58, i32 %%storemerge148, i32 %%48, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge1_2e__count);
  llvm_cbe_storemerge1_2e_ = (unsigned int )((((llvm_cbe_tmp__142&4294967295U) == (0u&4294967295U))) ? ((unsigned int )llvm_cbe_storemerge148) : ((unsigned int )llvm_cbe_tmp__143));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge1. = 0x%X\n", llvm_cbe_storemerge1_2e_);
  llvm_cbe_tmp__151__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge7_2e_;   /* for PHI node */
  llvm_cbe_tmp__152__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge1_2e_;   /* for PHI node */
  llvm_cbe_tmp__153__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__150;   /* for PHI node */
  goto llvm_cbe_tmp__203;

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader40' */
llvm_cbe_tmp__202:
  if (((llvm_cbe_tmp__153&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__205;
  } else {
    goto llvm_cbe_tmp__206;
  }

llvm_cbe_tmp__205:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts21 = tail call i32 @puts(i8* getelementptr inbounds ([27 x i8]* @aesl_internal_str14, i64 0, i64 0)), !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts21_count);
   /*tail*/ puts(( char *)((&aesl_internal_str14[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 27
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts21 = 0x%X",llvm_cbe_puts21);
}
  goto llvm_cbe_tmp__207;

llvm_cbe_tmp__206:
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str24, i64 0, i64 0), i32 %%62) nounwind, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_726_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str24[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), llvm_cbe_tmp__153);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__153);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__156);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = sext i32 %%60 to i64, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_727_count);
  llvm_cbe_tmp__157 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__151);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__157);
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = sext i32 %%61 to i64, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_728_count);
  llvm_cbe_tmp__158 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__152);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__158);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = getelementptr inbounds [256 x [256 x i8]]* @aesl_internal_main.C_hw, i64 0, i64 %%72, i64 %%71, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_729_count);
  llvm_cbe_tmp__159 = ( char *)(&aesl_internal_main_OC_C_hw[(((signed long long )llvm_cbe_tmp__158))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__157))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__158));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__157));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__158) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_hw' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__157) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_hw' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = load i8* %%73, align 1, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_730_count);
  llvm_cbe_tmp__160 = (unsigned char )*llvm_cbe_tmp__159;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__160);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = zext i8 %%74 to i32, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_731_count);
  llvm_cbe_tmp__161 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__160&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__161);
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = getelementptr inbounds [256 x [256 x i8]]* @aesl_internal_main.C_sw, i64 0, i64 %%72, i64 %%71, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_732_count);
  llvm_cbe_tmp__162 = ( char *)(&aesl_internal_main_OC_C_sw[(((signed long long )llvm_cbe_tmp__158))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__157))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__158));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__157));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__158) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_sw' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__157) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_sw' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = load i8* %%76, align 1, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_733_count);
  llvm_cbe_tmp__163 = (unsigned char )*llvm_cbe_tmp__162;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__163);
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = zext i8 %%77 to i32, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_734_count);
  llvm_cbe_tmp__164 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__163&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__164);
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([41 x i8]* @aesl_internal_.str20, i64 0, i64 0), i32 %%61, i32 %%60, i32 %%75, i32 %%78) nounwind, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_735_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str20[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 41
#endif
])), llvm_cbe_tmp__152, llvm_cbe_tmp__151, llvm_cbe_tmp__161, llvm_cbe_tmp__164);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__152);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__151);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__161);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__164);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__165);
}
  goto llvm_cbe_tmp__207;

llvm_cbe_tmp__207:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @calculate_statistics([256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.C_hw, i64 0, i64 0)), !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_737_count);
   /*tail*/ calculate_statistics(((&aesl_internal_main_OC_C_hw[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts22 = tail call i32 @puts(i8* getelementptr inbounds ([33 x i8]* @aesl_internal_str15, i64 0, i64 0)), !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts22_count);
   /*tail*/ puts(( char *)((&aesl_internal_str15[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 33
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts22 = 0x%X",llvm_cbe_puts22);
}
  llvm_cbe_storemerge239__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader37;

  do {     /* Syntactic loop '.preheader37' to make GCC happy */
llvm_cbe__2e_preheader37:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge239 = phi i32 [ 0, %%80 ], [ %%104, %%103  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge239_count);
  llvm_cbe_storemerge239 = (unsigned int )llvm_cbe_storemerge239__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge239 = 0x%X",llvm_cbe_storemerge239);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__179);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = sext i32 %%storemerge239 to i64, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_788_count);
  llvm_cbe_tmp__166 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge239);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__166);
  llvm_cbe_storemerge638__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__208;

llvm_cbe_tmp__209:
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = add nsw i32 %%storemerge239, 1, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_842_count);
  llvm_cbe_tmp__179 = (unsigned int )((unsigned int )(llvm_cbe_storemerge239&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__179&4294967295ull)));
  if (((llvm_cbe_tmp__179&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__210;
  } else {
    llvm_cbe_storemerge239__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__179;   /* for PHI node */
    goto llvm_cbe__2e_preheader37;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__208:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge638 = phi i32 [ 0, %%.preheader37 ], [ %%102, %%101  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge638_count);
  llvm_cbe_storemerge638 = (unsigned int )llvm_cbe_storemerge638__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge638 = 0x%X",llvm_cbe_storemerge638);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__178);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = add nsw i32 %%storemerge638, %%storemerge239, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_790_count);
  llvm_cbe_tmp__167 = (unsigned int )((unsigned int )(llvm_cbe_storemerge638&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge239&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__167&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = srem i32 %%83, 3, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_791_count);
  llvm_cbe_tmp__168 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__167) % ((signed int )3u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__168));
  if (((llvm_cbe_tmp__168&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__211;
  } else {
    goto llvm_cbe_tmp__212;
  }

llvm_cbe_tmp__213:
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = add nsw i32 %%storemerge638, 1, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_815_count);
  llvm_cbe_tmp__178 = (unsigned int )((unsigned int )(llvm_cbe_storemerge638&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__178&4294967295ull)));
  if (((llvm_cbe_tmp__178&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__209;
  } else {
    llvm_cbe_storemerge638__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__178;   /* for PHI node */
    goto llvm_cbe_tmp__208;
  }

llvm_cbe_tmp__211:
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = sext i32 %%storemerge638 to i64, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_794_count);
  llvm_cbe_tmp__169 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge638);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__169);
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = getelementptr inbounds [256 x [256 x i8]]* @aesl_internal_main.A, i64 0, i64 %%81, i64 %%87, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_795_count);
  llvm_cbe_tmp__170 = ( char *)(&aesl_internal_main_OC_A[(((signed long long )llvm_cbe_tmp__166))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__169))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__166));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__169));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__166) < 256 && "Write access out of array 'aesl_internal_main.A' bound?");
  assert(((signed long long )llvm_cbe_tmp__169) < 256 && "Write access out of array 'aesl_internal_main.A' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%88, align 1, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_796_count);
  *llvm_cbe_tmp__170 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = getelementptr inbounds [256 x [256 x i8]]* @aesl_internal_main.B, i64 0, i64 %%81, i64 %%87, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_797_count);
  llvm_cbe_tmp__171 = ( char *)(&aesl_internal_main_OC_B[(((signed long long )llvm_cbe_tmp__166))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__169))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__166));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__169));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__166) < 256 && "Write access out of array 'aesl_internal_main.B' bound?");
  assert(((signed long long )llvm_cbe_tmp__169) < 256 && "Write access out of array 'aesl_internal_main.B' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 31, i8* %%89, align 1, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_798_count);
  *llvm_cbe_tmp__171 = ((unsigned char )31);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )31));
  goto llvm_cbe_tmp__213;

llvm_cbe_tmp__214:
  goto llvm_cbe_tmp__213;

llvm_cbe_tmp__215:
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = sext i32 %%storemerge638 to i64, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_802_count);
  llvm_cbe_tmp__172 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge638);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__172);
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = getelementptr inbounds [256 x [256 x i8]]* @aesl_internal_main.A, i64 0, i64 %%81, i64 %%93, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_803_count);
  llvm_cbe_tmp__173 = ( char *)(&aesl_internal_main_OC_A[(((signed long long )llvm_cbe_tmp__166))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__172))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__166));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__172));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__166) < 256 && "Write access out of array 'aesl_internal_main.A' bound?");
  assert(((signed long long )llvm_cbe_tmp__172) < 256 && "Write access out of array 'aesl_internal_main.A' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%94, align 1, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_804_count);
  *llvm_cbe_tmp__173 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = getelementptr inbounds [256 x [256 x i8]]* @aesl_internal_main.B, i64 0, i64 %%81, i64 %%93, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_805_count);
  llvm_cbe_tmp__174 = ( char *)(&aesl_internal_main_OC_B[(((signed long long )llvm_cbe_tmp__166))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__172))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__166));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__172));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__166) < 256 && "Write access out of array 'aesl_internal_main.B' bound?");
  assert(((signed long long )llvm_cbe_tmp__172) < 256 && "Write access out of array 'aesl_internal_main.B' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 33, i8* %%95, align 1, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_806_count);
  *llvm_cbe_tmp__174 = ((unsigned char )33);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )33));
  goto llvm_cbe_tmp__214;

llvm_cbe_tmp__212:
  if (((llvm_cbe_tmp__168&4294967295U) == (1u&4294967295U))) {
    goto llvm_cbe_tmp__215;
  } else {
    goto llvm_cbe_tmp__216;
  }

llvm_cbe_tmp__216:
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = sext i32 %%storemerge638 to i64, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_808_count);
  llvm_cbe_tmp__175 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge638);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__175);
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = getelementptr inbounds [256 x [256 x i8]]* @aesl_internal_main.A, i64 0, i64 %%81, i64 %%97, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_809_count);
  llvm_cbe_tmp__176 = ( char *)(&aesl_internal_main_OC_A[(((signed long long )llvm_cbe_tmp__166))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__175))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__166));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__175));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__166) < 256 && "Write access out of array 'aesl_internal_main.A' bound?");
  assert(((signed long long )llvm_cbe_tmp__175) < 256 && "Write access out of array 'aesl_internal_main.A' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%98, align 1, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_810_count);
  *llvm_cbe_tmp__176 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = getelementptr inbounds [256 x [256 x i8]]* @aesl_internal_main.B, i64 0, i64 %%81, i64 %%97, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_811_count);
  llvm_cbe_tmp__177 = ( char *)(&aesl_internal_main_OC_B[(((signed long long )llvm_cbe_tmp__166))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__175))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__166));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__175));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__166) < 256 && "Write access out of array 'aesl_internal_main.B' bound?");
  assert(((signed long long )llvm_cbe_tmp__175) < 256 && "Write access out of array 'aesl_internal_main.B' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 96, i8* %%99, align 1, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_812_count);
  *llvm_cbe_tmp__177 = ((unsigned char )96);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )96));
  goto llvm_cbe_tmp__214;

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader37' */
llvm_cbe_tmp__210:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts23 = tail call i32 @puts(i8* getelementptr inbounds ([31 x i8]* @aesl_internal_str16, i64 0, i64 0)), !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts23_count);
   /*tail*/ puts(( char *)((&aesl_internal_str16[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 31
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts23 = 0x%X",llvm_cbe_puts23);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @image_diff_posterize_sw_ref([256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.A, i64 0, i64 0), [256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.B, i64 0, i64 0), [256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.C_sw, i64 0, i64 0)), !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_869_count);
   /*tail*/ image_diff_posterize_sw_ref(((&aesl_internal_main_OC_A[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), ((&aesl_internal_main_OC_B[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), ((&aesl_internal_main_OC_C_sw[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts24 = tail call i32 @puts(i8* getelementptr inbounds ([32 x i8]* @aesl_internal_str17, i64 0, i64 0)), !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts24_count);
   /*tail*/ puts(( char *)((&aesl_internal_str17[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts24 = 0x%X",llvm_cbe_puts24);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @apatb_image_diff_posterize_sw([256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.A, i64 0, i64 0), [256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.B, i64 0, i64 0), [256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.C_hw, i64 0, i64 0)) nounwind, !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_870_count);
   /*tail*/ apatb_image_diff_posterize_sw(((&aesl_internal_main_OC_A[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), ((&aesl_internal_main_OC_B[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])), ((&aesl_internal_main_OC_C_hw[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts25 = tail call i32 @puts(i8* getelementptr inbounds ([22 x i8]* @aesl_internal_str18, i64 0, i64 0)), !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts25_count);
   /*tail*/ puts(( char *)((&aesl_internal_str18[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 22
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts25 = 0x%X",llvm_cbe_puts25);
}
  llvm_cbe_storemerge336__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__180__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge336 = phi i32 [ 0, %%105 ], [ %%119, %%118  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge336_count);
  llvm_cbe_storemerge336 = (unsigned int )llvm_cbe_storemerge336__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge336 = 0x%X",llvm_cbe_storemerge336);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__190);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = phi i32 [ 0, %%105 ], [ %%., %%118  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_909_count);
  llvm_cbe_tmp__180 = (unsigned int )llvm_cbe_tmp__180__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__180);
printf("\n = 0x%X",0u);
printf("\n. = 0x%X",llvm_cbe__2e_);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = sext i32 %%storemerge336 to i64, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_934_count);
  llvm_cbe_tmp__181 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge336);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__181);
  llvm_cbe_storemerge534__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__182__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__180;   /* for PHI node */
  goto llvm_cbe_tmp__217;

llvm_cbe_tmp__218:
if (AESL_DEBUG_TRACE)
printf("\n  %%119 = add nsw i32 %%storemerge336, 1, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_983_count);
  llvm_cbe_tmp__190 = (unsigned int )((unsigned int )(llvm_cbe_storemerge336&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__190&4294967295ull)));
  if (((llvm_cbe_tmp__190&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__219;
  } else {
    llvm_cbe_storemerge336__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__190;   /* for PHI node */
    llvm_cbe_tmp__180__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__217:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge534 = phi i32 [ 0, %%.preheader ], [ %%117, %%108  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge534_count);
  llvm_cbe_storemerge534 = (unsigned int )llvm_cbe_storemerge534__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge534 = 0x%X",llvm_cbe_storemerge534);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__189);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = phi i32 [ %%106, %%.preheader ], [ %%., %%108  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_936_count);
  llvm_cbe_tmp__182 = (unsigned int )llvm_cbe_tmp__182__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__182);
printf("\n = 0x%X",llvm_cbe_tmp__180);
printf("\n. = 0x%X",llvm_cbe__2e_);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%110 = sext i32 %%storemerge534 to i64, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_937_count);
  llvm_cbe_tmp__183 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge534);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__183);
if (AESL_DEBUG_TRACE)
printf("\n  %%111 = getelementptr inbounds [256 x [256 x i8]]* @aesl_internal_main.C_hw, i64 0, i64 %%107, i64 %%110, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_938_count);
  llvm_cbe_tmp__184 = ( char *)(&aesl_internal_main_OC_C_hw[(((signed long long )llvm_cbe_tmp__181))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__183))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__181));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__183));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__181) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_hw' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__183) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_hw' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%112 = load i8* %%111, align 1, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_939_count);
  llvm_cbe_tmp__185 = (unsigned char )*llvm_cbe_tmp__184;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__185);
if (AESL_DEBUG_TRACE)
printf("\n  %%113 = getelementptr inbounds [256 x [256 x i8]]* @aesl_internal_main.C_sw, i64 0, i64 %%107, i64 %%110, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_940_count);
  llvm_cbe_tmp__186 = ( char *)(&aesl_internal_main_OC_C_sw[(((signed long long )llvm_cbe_tmp__181))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__183))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__181));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__183));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__181) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_sw' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__183) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_main.C_sw' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%114 = load i8* %%113, align 1, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_941_count);
  llvm_cbe_tmp__187 = (unsigned char )*llvm_cbe_tmp__186;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__187);
if (AESL_DEBUG_TRACE)
printf("\n  %%116 = add nsw i32 %%109, 1, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_943_count);
  llvm_cbe_tmp__188 = (unsigned int )((unsigned int )(llvm_cbe_tmp__182&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__188&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%115, i32 %%109, i32 %%116, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )((((llvm_cbe_tmp__185&255U) == (llvm_cbe_tmp__187&255U))) ? ((unsigned int )llvm_cbe_tmp__182) : ((unsigned int )llvm_cbe_tmp__188));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
if (AESL_DEBUG_TRACE)
printf("\n  %%117 = add nsw i32 %%storemerge534, 1, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_956_count);
  llvm_cbe_tmp__189 = (unsigned int )((unsigned int )(llvm_cbe_storemerge534&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__189&4294967295ull)));
  if (((llvm_cbe_tmp__189&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__218;
  } else {
    llvm_cbe_storemerge534__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__189;   /* for PHI node */
    llvm_cbe_tmp__182__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_;   /* for PHI node */
    goto llvm_cbe_tmp__217;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__219:
  if (((llvm_cbe__2e_&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__220;
  } else {
    goto llvm_cbe_tmp__221;
  }

llvm_cbe_tmp__220:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts26 = tail call i32 @puts(i8* getelementptr inbounds ([27 x i8]* @aesl_internal_str19, i64 0, i64 0)), !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts26_count);
   /*tail*/ puts(( char *)((&aesl_internal_str19[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 27
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts26 = 0x%X",llvm_cbe_puts26);
}
  goto llvm_cbe_tmp__222;

llvm_cbe_tmp__221:
if (AESL_DEBUG_TRACE)
printf("\n  %%124 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str27, i64 0, i64 0), i32 %%.) nounwind, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_1013_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str27[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), llvm_cbe__2e_);
if (AESL_DEBUG_TRACE) {
printf("\nArgument . = 0x%X",llvm_cbe__2e_);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__191);
}
  goto llvm_cbe_tmp__222;

llvm_cbe_tmp__222:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @calculate_statistics([256 x i8]* getelementptr inbounds ([256 x [256 x i8]]* @aesl_internal_main.C_hw, i64 0, i64 0)), !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_1015_count);
   /*tail*/ calculate_statistics(((&aesl_internal_main_OC_C_hw[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts27 = tail call i32 @puts(i8* getelementptr inbounds ([51 x i8]* @aesl_internal_str20, i64 0, i64 0)), !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts27_count);
   /*tail*/ puts(( char *)((&aesl_internal_str20[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 51
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts27 = 0x%X",llvm_cbe_puts27);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts28 = tail call i32 @puts(i8* getelementptr inbounds ([23 x i8]* @aesl_internal_str21, i64 0, i64 0)), !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts28_count);
   /*tail*/ puts(( char *)((&aesl_internal_str21[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 23
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts28 = 0x%X",llvm_cbe_puts28);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts29 = tail call i32 @puts(i8* getelementptr inbounds ([50 x i8]* @aesl_internal_str22, i64 0, i64 0)), !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts29_count);
   /*tail*/ puts(( char *)((&aesl_internal_str22[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 50
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts29 = 0x%X",llvm_cbe_puts29);
}
  if (((llvm_cbe__2e_&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__223;
  } else {
    goto llvm_cbe_tmp__224;
  }

llvm_cbe_tmp__223:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts30 = tail call i32 @puts(i8* getelementptr inbounds ([25 x i8]* @aesl_internal_str23, i64 0, i64 0)), !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts30_count);
   /*tail*/ puts(( char *)((&aesl_internal_str23[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 25
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts30 = 0x%X",llvm_cbe_puts30);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts31 = tail call i32 @puts(i8* getelementptr inbounds ([38 x i8]* @aesl_internal_str24, i64 0, i64 0)), !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts31_count);
   /*tail*/ puts(( char *)((&aesl_internal_str24[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 38
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts31 = 0x%X",llvm_cbe_puts31);
}
  llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__225;

llvm_cbe_tmp__224:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts32 = tail call i32 @puts(i8* getelementptr inbounds ([26 x i8]* @aesl_internal_str25, i64 0, i64 0)), !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts32_count);
   /*tail*/ puts(( char *)((&aesl_internal_str25[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 26
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts32 = 0x%X",llvm_cbe_puts32);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts33 = tail call i32 @puts(i8* getelementptr inbounds ([54 x i8]* @aesl_internal_str26, i64 0, i64 0)), !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts33_count);
   /*tail*/ puts(( char *)((&aesl_internal_str26[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 54
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts33 = 0x%X",llvm_cbe_puts33);
}
  llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe_tmp__225;

llvm_cbe_tmp__225:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4 = phi i32 [ 0, %%126 ], [ 1, %%127  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge4_count);
  llvm_cbe_storemerge4 = (unsigned int )llvm_cbe_storemerge4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4 = 0x%X",llvm_cbe_storemerge4);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",1u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_storemerge4;
}

