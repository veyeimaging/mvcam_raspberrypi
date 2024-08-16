/*
Copyright (c) 2022, xumm,Tianjin Zhonanyijia Tech.
All rights reserved.
*/

#ifndef MV_IMX287_MODES_H_
#define MV_IMX287_MODES_H_
#include "mv_regs.h"   

#define IMX287_FULL_WIDTH  704
#define IMX287_FULL_HEIGHT  544

struct sensor_regs mv_imx287_common_init[] =
{
    
};

struct sensor_regs mv_imx287_full_8bit_regs[] = 
{
    {Image_Acquisition, 0x00},  /* stop */
    {Pixel_Format,0x0},
    {Image_Acquisition, 0x01},  /* start */
};

struct sensor_regs mv_imx287_full_10bit_regs[] = 
{
    {Image_Acquisition, 0x00},  /* stop */
    {Pixel_Format,0x1},
    {Image_Acquisition, 0x01},  /* start */
};

struct sensor_regs mv_imx287_full_12bit_regs[] = 
{
    {Image_Acquisition, 0x00},  /* stop */
    {Pixel_Format,0x2},
    {Image_Acquisition, 0x01},  /* start */
};

//default value
struct sensor_regs mv_imx287_roi_regs[] = 
{
    {ROI_Offset_X, 0x00},
    {ROI_Offset_Y, 0x00},
    {ROI_Width, IMX287_FULL_WIDTH},
    {0xFFFE,10},//sleep 10ms
    {ROI_Height, IMX287_FULL_HEIGHT},
};

struct mode_def mv_imx287_modes[] = {
   {
      .regs          = mv_imx287_full_8bit_regs,
      .num_regs      = NUM_ELEMENTS(mv_imx287_full_8bit_regs),
      
      .width         = IMX287_FULL_WIDTH,//
      .height        = IMX287_FULL_HEIGHT,//
      .encoding      = 0,//
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
   {
      .regs          = mv_imx287_full_10bit_regs,
      .num_regs      = NUM_ELEMENTS(mv_imx287_full_10bit_regs),
      
      .width         = IMX287_FULL_WIDTH,//
      .height        = IMX287_FULL_HEIGHT,//
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
   {
      .regs          = mv_imx287_full_12bit_regs,
      .num_regs      = NUM_ELEMENTS(mv_imx287_full_10bit_regs),
      
      .width         = IMX287_FULL_WIDTH,//
      .height        = IMX287_FULL_HEIGHT,//
      .encoding      = 0,//MMAL_ENCODING_Y12,
      .order         = BAYER_ORDER_RGGB,//BAYER_ORDER_GRAY,
      .native_bit_depth = 12,// 
      .image_id      = 0x2C,//raw12
      .data_lanes    = 2,
      .min_vts       = 1118,//1118,
      .line_time_ns  = 14815,//1456 pixels per line
      .timing        = {0, 0, 0, 0, 0},
      .term          = {0, 0},
      .black_level   = 0,
   },
};

struct sensor_regs mv_imx287_stop[] = {
      {Image_Acquisition, 0x00},          /* disable streaming  */
};

struct sensor_def mv_imx287 = {
      .name =                 "mv_imx287",
      .common_init =          mv_imx287_common_init,
      .num_common_init =      NUM_ELEMENTS(mv_imx287_common_init),
      .modes =                mv_imx287_modes,
      .num_modes =            NUM_ELEMENTS(mv_imx287_modes),
      .stop =                 mv_imx287_stop,
      .num_stop_regs =        NUM_ELEMENTS(mv_imx287_stop),

      .roi = mv_imx287_roi_regs,
	  .num_roi_regs = NUM_ELEMENTS(mv_imx287_roi_regs),
	  
      .i2c_addr =             0x3b,
      .i2c_addressing =       2,
      .i2c_data_size =        4,
      
      .i2c_ident_length =     1,
      
      
      .i2c_ident_reg =        Model_Name,
      .i2c_ident_value =      0x287,

      .vflip_reg =            Image_Direction,
      .vflip_reg_bit =        1,
      .hflip_reg =            Image_Direction,
      .hflip_reg_bit =        0,
      //manual exp
      .exposure_reg =         0x0c10,
      .exposure_reg_num_bits = 32,
       //todo
      .vts_reg =              0x3018,
      .vts_reg_num_bits =     16,

      .gain_reg =             0x0c20,
      .gain_reg_num_bits =    32,
};

#endif


