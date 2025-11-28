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
void image_diff_posterize( char (*llvm_cbe_A)[256],  char (*llvm_cbe_B)[256],  char (*llvm_cbe_C)[256]);


/* Global Variable Definitions and Initialization */
static  char aesl_internal_image_diff_posterize_OC_rowA[256];
static  char aesl_internal_image_diff_posterize_OC_rowB[256];
static  char aesl_internal_image_diff_posterize_OC_rowC[256];


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

void image_diff_posterize( char (*llvm_cbe_A)[256],  char (*llvm_cbe_B)[256],  char (*llvm_cbe_C)[256]) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge9_count = 0;
  unsigned int llvm_cbe_storemerge9;
  unsigned int llvm_cbe_storemerge9__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned long long llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge18_count = 0;
  unsigned int llvm_cbe_storemerge18;
  unsigned int llvm_cbe_storemerge18__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
   char *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned char llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
   char *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
   char *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned char llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
   char *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond11_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge26_count = 0;
  unsigned int llvm_cbe_storemerge26;
  unsigned int llvm_cbe_storemerge26__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned long long llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
   char *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  unsigned char llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned short llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
   char *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  unsigned char llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  unsigned short llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned short llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  unsigned char llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  unsigned char llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned char llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_in_count = 0;
  unsigned char llvm_cbe__2e_in;
  unsigned char llvm_cbe__2e_in__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
   char *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
   char *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
   char *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond10_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge34_count = 0;
  unsigned int llvm_cbe_storemerge34;
  unsigned int llvm_cbe_storemerge34__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  unsigned long long llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
   char *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  unsigned char llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
   char *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond12_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @image_diff_posterize\n");
  llvm_cbe_storemerge9__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader7;

  do {     /* Syntactic loop '.preheader7' to make GCC happy */
llvm_cbe__2e_preheader7:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge9 = phi i32 [ 0, %%0 ], [ %%44, %%43  for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_storemerge9_count);
  llvm_cbe_storemerge9 = (unsigned int )llvm_cbe_storemerge9__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge9 = 0x%X",llvm_cbe_storemerge9);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__30);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = sext i32 %%storemerge9 to i64, !dbg !3 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__1 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge9);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__1);
  llvm_cbe_storemerge18__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__31;

llvm_cbe_tmp__32:
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = add nsw i32 %%storemerge9, 1, !dbg !5 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__30 = (unsigned int )((unsigned int )(llvm_cbe_storemerge9&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__30&4294967295ull)));
  if (((llvm_cbe_tmp__30&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__33;
  } else {
    llvm_cbe_storemerge9__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__30;   /* for PHI node */
    goto llvm_cbe__2e_preheader7;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge34 = phi i32 [ %%42, %%.preheader ], [ 0, %%36  for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_storemerge34_count);
  llvm_cbe_storemerge34 = (unsigned int )llvm_cbe_storemerge34__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge34 = 0x%X",llvm_cbe_storemerge34);
printf("\n = 0x%X",llvm_cbe_tmp__29);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = sext i32 %%storemerge34 to i64, !dbg !4 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__25 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge34);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds [256 x i8]* @aesl_internal_image_diff_posterize.rowC, i64 0, i64 %%38, !dbg !4 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__26 = ( char *)(&aesl_internal_image_diff_posterize_OC_rowC[(((signed long long )llvm_cbe_tmp__25))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__25));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__25) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_image_diff_posterize.rowC' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i8* %%39, align 1, !dbg !4 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__27 = (unsigned char )*llvm_cbe_tmp__26;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds [256 x i8]* %%C, i64 %%1, i64 %%38, !dbg !4 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__28 = ( char *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__1))
#ifdef AESL_BC_SIM
 % 256
#endif
][(((signed long long )llvm_cbe_tmp__25))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__25));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__25) < 256 && "Write access out of array 'C' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%40, i8* %%41, align 1, !dbg !4 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_122_count);
  *llvm_cbe_tmp__28 = llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add nsw i32 %%storemerge34, 1, !dbg !6 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__29 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__29&4294967295ull)));
  if (((llvm_cbe_tmp__29&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__32;
  } else {
    llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__29;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
  do {     /* Syntactic loop '.preheader5' to make GCC happy */
llvm_cbe__2e_preheader5:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge26 = phi i32 [ %%37, %%36 ], [ 0, %%2  for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_storemerge26_count);
  llvm_cbe_storemerge26 = (unsigned int )llvm_cbe_storemerge26__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge26 = 0x%X",llvm_cbe_storemerge26);
printf("\n = 0x%X",llvm_cbe_tmp__24);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%storemerge26 to i64, !dbg !5 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__10 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge26);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [256 x i8]* @aesl_internal_image_diff_posterize.rowA, i64 0, i64 %%11, !dbg !5 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__11 = ( char *)(&aesl_internal_image_diff_posterize_OC_rowA[(((signed long long )llvm_cbe_tmp__10))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__10));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__10) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_image_diff_posterize.rowA' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i8* %%12, align 1, !dbg !5 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__12 = (unsigned char )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i8 %%13 to i16, !dbg !5 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__13 = (unsigned short )((unsigned short )(unsigned char )llvm_cbe_tmp__12&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [256 x i8]* @aesl_internal_image_diff_posterize.rowB, i64 0, i64 %%11, !dbg !5 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__14 = ( char *)(&aesl_internal_image_diff_posterize_OC_rowB[(((signed long long )llvm_cbe_tmp__10))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__10));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__10) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_image_diff_posterize.rowB' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i8* %%15, align 1, !dbg !5 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__15 = (unsigned char )*llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = zext i8 %%16 to i16, !dbg !5 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__16 = (unsigned short )((unsigned short )(unsigned char )llvm_cbe_tmp__15&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = sub i16 %%14, %%17, !dbg !5 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__17 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__13&65535ull)) - ((unsigned short )(llvm_cbe_tmp__16&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__17&65535ull)));
  if ((((signed short )llvm_cbe_tmp__17) < ((signed short )((unsigned short )0)))) {
    goto llvm_cbe_tmp__34;
  } else {
    goto llvm_cbe_tmp__35;
  }

llvm_cbe_tmp__36:
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = add nsw i32 %%storemerge26, 1, !dbg !6 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_98_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )(llvm_cbe_storemerge26&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__24&4294967295ull)));
  if (((llvm_cbe_tmp__24&4294967295U) == (256u&4294967295U))) {
    llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge26__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__24;   /* for PHI node */
    goto llvm_cbe__2e_preheader5;
  }

llvm_cbe_tmp__37:
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds [256 x i8]* @aesl_internal_image_diff_posterize.rowC, i64 0, i64 %%11, !dbg !5 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__21 = ( char *)(&aesl_internal_image_diff_posterize_OC_rowC[(((signed long long )llvm_cbe_tmp__10))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__10));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__10) < 256 && "Write access out of array 'aesl_internal_image_diff_posterize.rowC' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%28, align 1, !dbg !5 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_87_count);
  *llvm_cbe_tmp__21 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
  goto llvm_cbe_tmp__36;

llvm_cbe_tmp__38:
if (AESL_DEBUG_TRACE)
printf("\n  %%.in = phi i8 [ %%22, %%20 ], [ %%24, %%23 ], !dbg !6 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe__2e_in_count);
  llvm_cbe__2e_in = (unsigned char )llvm_cbe__2e_in__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.in = 0x%X",llvm_cbe__2e_in);
printf("\n = 0x%X",llvm_cbe_tmp__19);
printf("\n = 0x%X",llvm_cbe_tmp__20);
}
  if ((((unsigned char )llvm_cbe__2e_in&255U) < ((unsigned char )((unsigned char )32)&255U))) {
    goto llvm_cbe_tmp__37;
  } else {
    goto llvm_cbe_tmp__39;
  }

llvm_cbe_tmp__34:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = trunc i16 %%18 to i8, !dbg !6 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__18 = (unsigned char )((unsigned char )llvm_cbe_tmp__17&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = sub i8 0, %%21, !dbg !6 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__19 = (unsigned char )((unsigned char )(-(llvm_cbe_tmp__18)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__19&255ull)));
  llvm_cbe__2e_in__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__19;   /* for PHI node */
  goto llvm_cbe_tmp__38;

llvm_cbe_tmp__35:
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = trunc i16 %%18 to i8, !dbg !6 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__20 = (unsigned char )((unsigned char )llvm_cbe_tmp__17&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
  llvm_cbe__2e_in__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__20;   /* for PHI node */
  goto llvm_cbe_tmp__38;

llvm_cbe_tmp__40:
  goto llvm_cbe_tmp__36;

llvm_cbe_tmp__41:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds [256 x i8]* @aesl_internal_image_diff_posterize.rowC, i64 0, i64 %%11, !dbg !6 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__22 = ( char *)(&aesl_internal_image_diff_posterize_OC_rowC[(((signed long long )llvm_cbe_tmp__10))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__10));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__10) < 256 && "Write access out of array 'aesl_internal_image_diff_posterize.rowC' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 -128, i8* %%32, align 1, !dbg !6 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_92_count);
  *llvm_cbe_tmp__22 = ((unsigned char )128u);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )128u));
  goto llvm_cbe_tmp__40;

llvm_cbe_tmp__39:
  if ((((unsigned char )llvm_cbe__2e_in&255U) < ((unsigned char )((unsigned char )96)&255U))) {
    goto llvm_cbe_tmp__41;
  } else {
    goto llvm_cbe_tmp__42;
  }

llvm_cbe_tmp__42:
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds [256 x i8]* @aesl_internal_image_diff_posterize.rowC, i64 0, i64 %%11, !dbg !6 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__23 = ( char *)(&aesl_internal_image_diff_posterize_OC_rowC[(((signed long long )llvm_cbe_tmp__10))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__10));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__10) < 256 && "Write access out of array 'aesl_internal_image_diff_posterize.rowC' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 -1, i8* %%34, align 1, !dbg !6 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_95_count);
  *llvm_cbe_tmp__23 = ((unsigned char )-1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )-1));
  goto llvm_cbe_tmp__40;

  } while (1); /* end of syntactic loop '.preheader5' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__31:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge18 = phi i32 [ 0, %%.preheader7 ], [ %%10, %%2  for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_storemerge18_count);
  llvm_cbe_storemerge18 = (unsigned int )llvm_cbe_storemerge18__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge18 = 0x%X",llvm_cbe_storemerge18);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%storemerge18 to i64, !dbg !3 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__2 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge18);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [256 x i8]* %%A, i64 %%1, i64 %%3, !dbg !3 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_34_count);
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
printf("\n  %%5 = load i8* %%4, align 1, !dbg !3 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__4 = (unsigned char )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds [256 x i8]* @aesl_internal_image_diff_posterize.rowA, i64 0, i64 %%3, !dbg !3 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__5 = ( char *)(&aesl_internal_image_diff_posterize_OC_rowA[(((signed long long )llvm_cbe_tmp__2))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__2) < 256 && "Write access out of array 'aesl_internal_image_diff_posterize.rowA' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%5, i8* %%6, align 1, !dbg !3 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_37_count);
  *llvm_cbe_tmp__5 = llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [256 x i8]* %%B, i64 %%1, i64 %%3, !dbg !4 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_38_count);
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
printf("\n  %%8 = load i8* %%7, align 1, !dbg !4 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__7 = (unsigned char )*llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds [256 x i8]* @aesl_internal_image_diff_posterize.rowB, i64 0, i64 %%3, !dbg !4 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__8 = ( char *)(&aesl_internal_image_diff_posterize_OC_rowB[(((signed long long )llvm_cbe_tmp__2))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__2) < 256 && "Write access out of array 'aesl_internal_image_diff_posterize.rowB' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%8, i8* %%9, align 1, !dbg !4 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_41_count);
  *llvm_cbe_tmp__8 = llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%storemerge18, 1, !dbg !5 for 0x%I64xth hint within @image_diff_posterize  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__9 = (unsigned int )((unsigned int )(llvm_cbe_storemerge18&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__9&4294967295ull)));
  if (((llvm_cbe_tmp__9&4294967295U) == (256u&4294967295U))) {
    llvm_cbe_storemerge26__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader5;
  } else {
    llvm_cbe_storemerge18__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__9;   /* for PHI node */
    goto llvm_cbe_tmp__31;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader7' */
llvm_cbe_tmp__33:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @image_diff_posterize}\n");
  return;
}

