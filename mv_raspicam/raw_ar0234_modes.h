/*
Copyright (c) 2022, xumm,Tianjin Zhonanyijia Tech.
All rights reserved.
*/

#ifndef RAW_AR0234_MODES_H_
#define RAW_AR0234_MODES_H_
#include "mv_regs.h"   

#define AR0234_FULL_WIDTH  1920
#define AR0234_FULL_HEIGHT  1200

struct sensor_regs raw_ar0234_common_init[] =
{
    
};

struct sensor_regs raw_ar0234_full_8bit_2lane_regs[] = 
{
    {Image_Acquisition, 0x00},  /* stop */
    {Pixel_Format,0x0},
    {0xFFFE,400},//sleep 400ms
    {Lane_Num,0x2},
    {0xFFFE,400},//sleep 400ms

    {Image_Acquisition, 0x01},  /* start */
};

struct sensor_regs raw_ar0234_full_10bit_2lane_regs[] = 
{
    {Image_Acquisition, 0x00},  /* stop */
    {Pixel_Format,0x1},
    {0xFFFE,400},//sleep 400ms
    {Lane_Num,0x2},
    {0xFFFE,400},//sleep 400ms
    {Image_Acquisition, 0x01},  /* start */
};

struct sensor_regs raw_ar0234_full_8bit_4lane_regs[] = 
{
    {Image_Acquisition, 0x00},  /* stop */
    {Pixel_Format,0x0},
    {0xFFFE,400},//sleep 400ms
    {Lane_Num,0x4},
    {0xFFFE,400},//sleep 400ms
    {Image_Acquisition, 0x01},  /* start */
};

struct sensor_regs raw_ar0234_full_10bit_4lane_regs[] = 
{
    {Image_Acquisition, 0x00},  /* stop */
    {Pixel_Format,0x1},
    {0xFFFE,400},//sleep 400ms
    {Lane_Num,0x4},
    {0xFFFE,400},//sleep 400ms
    {Image_Acquisition, 0x01},  /* start */
};


//default value
struct sensor_regs raw_ar0234_roi_regs[] = 
{
    {ROI_Offset_X, 0x00},
    {ROI_Offset_Y, 0x00},
    {ROI_Width, AR0234_FULL_WIDTH},
    {0xFFFE,10},//sleep 10ms
    {ROI_Height, AR0234_FULL_HEIGHT},
};

struct mode_def raw_ar0234_modes[] = {

    //mode0 --2lan raw8
    {
      .regs          = raw_ar0234_full_8bit_2lane_regs,
      .num_regs      = NUM_ELEMENTS(raw_ar0234_full_8bit_2lane_regs),
      
      .width         = AR0234_FULL_WIDTH,//
      .height        = AR0234_FULL_HEIGHT,//
      .encoding      = 0,//MMAL_ENCODING_Y10,
      .order         = BAYER_ORDER_RGGB,//BAYER_ORDER_GRAY,

      .native_bit_depth = 8,// 
      .image_id      = 0x2A,//raw8

      .data_lanes    = 2,
      .min_vts       = 1118,//1118,
      .line_time_ns  = 14815,//1456 pixels per line
      .timing        = {0, 0, 0, 0, 0},
      .term          = {0, 0},
      .black_level   = 0,
   },
   //mode1 --2lan raw10
   {
      .regs          = raw_ar0234_full_10bit_2lane_regs,
      .num_regs      = NUM_ELEMENTS(raw_ar0234_full_10bit_2lane_regs),
      
      .width         = AR0234_FULL_WIDTH,//
      .height        = AR0234_FULL_HEIGHT,//
      .encoding      = 0,//MMAL_ENCODING_Y10,
      .order         = BAYER_ORDER_RGGB,//BAYER_ORDER_GRAY,
      .native_bit_depth = 10,// 
      .image_id      = 0x2B,//raw10
      
      .data_lanes    = 2,
      .min_vts       = 1118,//1118,
      .line_time_ns  = 14815,//1456 pixels per line
      .timing        = {0, 0, 0, 0, 0},
      .term          = {0, 0},
      .black_level   = 0,
   },
     //mode2 --4lan raw8
     {
       .regs          = raw_ar0234_full_8bit_4lane_regs,
       .num_regs      = NUM_ELEMENTS(raw_ar0234_full_8bit_4lane_regs),
       
       .width         = AR0234_FULL_WIDTH,//
       .height        = AR0234_FULL_HEIGHT,//
       .encoding      = 0,//MMAL_ENCODING_Y10,
       .order         = BAYER_ORDER_RGGB,//BAYER_ORDER_GRAY,
    
       .native_bit_depth = 8,// 
       .image_id      = 0x2A,//raw8
    
       .data_lanes    = 4,
       .min_vts       = 1118,//1118,
       .line_time_ns  = 14815,//1456 pixels per line
       .timing        = {0, 0, 0, 0, 0},
       .term          = {0, 0},
       .black_level   = 0,
    },
    //mode3 --4lan raw10
    {
       .regs          = raw_ar0234_full_10bit_4lane_regs,
       .num_regs      = NUM_ELEMENTS(raw_ar0234_full_10bit_4lane_regs),
       
       .width         = AR0234_FULL_WIDTH,//
       .height        = AR0234_FULL_HEIGHT,//
       .encoding      = 0,//MMAL_ENCODING_Y10,
       .order         = BAYER_ORDER_RGGB,//BAYER_ORDER_GRAY,
       .native_bit_depth = 10,// 
       .image_id      = 0x2B,//raw10
       
       .data_lanes    = 4,
       .min_vts       = 1118,//1118,
       .line_time_ns  = 14815,//1456 pixels per line
       .timing        = {0, 0, 0, 0, 0},
       .term          = {0, 0},
       .black_level   = 0,
    },


};

struct sensor_regs raw_ar0234_stop[] = {
      {Image_Acquisition, 0x00},          /* disable streaming  */
};

struct sensor_def raw_ar0234 = {
      .name =                 "raw_ar0234",
      .common_init =          raw_ar0234_common_init,
      .num_common_init =      NUM_ELEMENTS(raw_ar0234_common_init),
      .modes =                raw_ar0234_modes,
      .num_modes =            NUM_ELEMENTS(raw_ar0234_modes),
      .stop =                 raw_ar0234_stop,
      .num_stop_regs =        NUM_ELEMENTS(raw_ar0234_stop),

      .roi = raw_ar0234_roi_regs,
	  .num_roi_regs = NUM_ELEMENTS(raw_ar0234_roi_regs),
	  
      .i2c_addr =             0x3b,
      .i2c_addressing =       2,
      .i2c_data_size =        4,
      
      .i2c_ident_length =     1,
      
      
      .i2c_ident_reg =        Model_Name,
      .i2c_ident_value =      0x8234,

      .vflip_reg =            Image_Direction,
      .vflip_reg_bit =        1,
      .hflip_reg =            Image_Direction,
      .hflip_reg_bit =        0,
      //manual exp
      .exposure_reg =         0,
      .exposure_reg_num_bits = 0,
       
      .vts_reg =              0,
      .vts_reg_num_bits =     0,

      .gain_reg =             0,
      .gain_reg_num_bits =    0,
};

#endif


