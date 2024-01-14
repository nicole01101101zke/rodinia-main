//========================================================================================================================================================================================================200
//	DEFINE / INCLUDE
//========================================================================================================================================================================================================200

#define fp float

#ifdef RD_WG_SIZE_0_0
        #define NUMBER_THREADS RD_WG_SIZE_0_0
#elif defined(RD_WG_SIZE_0)
        #define NUMBER_THREADS RD_WG_SIZE_0
#elif defined(RD_WG_SIZE)
        #define NUMBER_THREADS RD_WG_SIZE
#else
        #define NUMBER_THREADS 256
#endif

#define CHECK 37
// #define TEST_CHECKSUM
// #define TEST_OUTPUT
// #define INIT

// need to define these for static allocation of constant memory in GPU, because it cannot be allocated dynamically
#define ENDO_POINTS 20
#define EPI_POINTS 31
#define ALL_POINTS 51

//========================================================================================================================================================================================================200
//	PARAMS_COMMON STRUCTURE
//========================================================================================================================================================================================================200

typedef struct params_common{

	//======================================================================================================================================================150
	//	HARDCODED INPUTS FROM MATLAB
	//======================================================================================================================================================150

	//====================================================================================================100
	//	UNIQUE PARAMETER STRUCTURE MEMORY SIZE
	//====================================================================================================100

	int common_change_mem;
	int common_mem;
	int unique_mem;

	//====================================================================================================100
	//	USER INPUT
	//====================================================================================================100

	int frames_processed;

	//====================================================================================================100
	//	CONSTANTS
	//====================================================================================================100

	int sSize;
	int tSize;
	int maxMove;
	fp alpha;

	//====================================================================================================100
	//	FRAME
	//====================================================================================================100

	int no_frames;
	int frame_rows;
	int frame_cols;
	int frame_elem;
	int frame_mem;

	//====================================================================================================100
	//	ENDO POINTS
	//====================================================================================================100

	int endoPoints;
	int endo_mem;

	//====================================================================================================100
	//	EPI POINTS
	//====================================================================================================100
	int epiPoints;
	int epi_mem;

	//====================================================================================================100
	//	ALL POINTS
	//====================================================================================================100

	int allPoints;

	//====================================================================================================100
	//	End
	//====================================================================================================100

	//======================================================================================================================================================150
	//	RIGHT TEMPLATE 	FROM 	TEMPLATE ARRAY
	//======================================================================================================================================================150

	int in_rows;
	int in_cols;
	int in_elem;
	int in_mem;

	//======================================================================================================================================================150
	//	IN_POINTER
	//======================================================================================================================================================150

	int in_pointer_mem;

	//======================================================================================================================================================150
	// 	AREA AROUND POINT		FROM	FRAME
	//======================================================================================================================================================150

	int in2_rows;
	int in2_cols;
	int in2_elem;
	int in2_mem;

	//======================================================================================================================================================150
	//	CONVOLUTION
	//======================================================================================================================================================150

	int conv_rows;
	int conv_cols;
	int conv_elem;
	int conv_mem;
	int ioffset;
	int joffset;

	//======================================================================================================================================================150
	//	CUMULATIVE SUM 1
	//======================================================================================================================================================150

	//====================================================================================================100
	//	PAD ARRAY, VERTICAL CUMULATIVE SUM
	//====================================================================================================100

	int in2_pad_add_rows;
	int in2_pad_add_cols;
	int in2_pad_cumv_rows;
	int in2_pad_cumv_cols;
	int in2_pad_cumv_elem;
	int in2_pad_cumv_mem;

	//====================================================================================================100
	//	SELECTION
	//====================================================================================================100

	int in2_pad_cumv_sel_rows;
	int in2_pad_cumv_sel_cols;
	int in2_pad_cumv_sel_elem;
	int in2_pad_cumv_sel_mem;
	int in2_pad_cumv_sel_rowlow;
	int in2_pad_cumv_sel_rowhig;
	int in2_pad_cumv_sel_collow;
	int in2_pad_cumv_sel_colhig;

	//====================================================================================================100
	//	SELECTION 2, SUBTRACTION, HORIZONTAL CUMULATIVE SUM
	//====================================================================================================100

	int in2_pad_cumv_sel2_rowlow;
	int in2_pad_cumv_sel2_rowhig;
	int in2_pad_cumv_sel2_collow;
	int in2_pad_cumv_sel2_colhig;
	int in2_sub_cumh_rows;
	int in2_sub_cumh_cols;
	int in2_sub_cumh_elem;
	int in2_sub_cumh_mem;

	//====================================================================================================100
	//	SELECTION
	//====================================================================================================100

	int in2_sub_cumh_sel_rows;
	int in2_sub_cumh_sel_cols;
	int in2_sub_cumh_sel_elem;
	int in2_sub_cumh_sel_mem;
	int in2_sub_cumh_sel_rowlow;
	int in2_sub_cumh_sel_rowhig;
	int in2_sub_cumh_sel_collow;
	int in2_sub_cumh_sel_colhig;

	//====================================================================================================100
	//	SELECTION 2, SUBTRACTION
	//====================================================================================================100

	int in2_sub_cumh_sel2_rowlow;
	int in2_sub_cumh_sel2_rowhig;
	int in2_sub_cumh_sel2_collow;
	int in2_sub_cumh_sel2_colhig;
	int in2_sub2_rows;
	int in2_sub2_cols;
	int in2_sub2_elem;
	int in2_sub2_mem;

	//====================================================================================================100
	//	End
	//====================================================================================================100

	//======================================================================================================================================================150
	//	CUMULATIVE SUM 2
	//======================================================================================================================================================150

	//====================================================================================================100
	//	MULTIPLICATION
	//====================================================================================================100

	int in2_sqr_rows;
	int in2_sqr_cols;
	int in2_sqr_elem;
	int in2_sqr_mem;

	//====================================================================================================100
	//	SELECTION 2, SUBTRACTION
	//====================================================================================================100

	int in2_sqr_sub2_rows;
	int in2_sqr_sub2_cols;
	int in2_sqr_sub2_elem;
	int in2_sqr_sub2_mem;

	//====================================================================================================100
	//	End
	//====================================================================================================100

	//======================================================================================================================================================150
	//	FINAL
	//======================================================================================================================================================150

	int in_sqr_rows;
	int in_sqr_cols;
	int in_sqr_elem;
	int in_sqr_mem;

	//======================================================================================================================================================150
	//	TEMPLATE MASK CREATE
	//======================================================================================================================================================150

	int tMask_rows;
	int tMask_cols;
	int tMask_elem;
	int tMask_mem;

	//======================================================================================================================================================150
	//	POINT MASK INITIALIZE
	//======================================================================================================================================================150

	int mask_rows;
	int mask_cols;
	int mask_elem;
	int mask_mem;

	//======================================================================================================================================================150
	//	MASK CONVOLUTION
	//======================================================================================================================================================150

	int mask_conv_rows;
	int mask_conv_cols;
	int mask_conv_elem;
	int mask_conv_mem;
	int mask_conv_ioffset;
	int mask_conv_joffset;

	//======================================================================================================================================================150
	//	End
	//======================================================================================================================================================150

} params_common;

//========================================================================================================================================================================================================200
//	END OF STRUCTURE
//========================================================================================================================================================================================================200
