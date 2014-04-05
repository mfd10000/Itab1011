/* arch/arm/mach-rk30/board-rk30-sdk-sdmmc.c
 *
 * Copyright (C) 2012 ROCKCHIP, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifdef CONFIG_SDMMC_RK29

#if !defined(CONFIG_SDMMC_RK29_OLD)	
static void rk29_sdmmc_gpio_open(int device_id, int on)
{
    switch(device_id)
    {
        case 0://mmc0
        {	pr_info("am intrat la initializare pe mmc0");
            #ifdef CONFIG_SDMMC0_RK29
            if(on)
            {	pr_info("daca pe mmc0 pornit...");
                gpio_direction_output(GPIO3B_GPIO3B0,GPIO_HIGH);//set mmc0-clk to high
                gpio_direction_output(GPIO3B_GPIO3B1,GPIO_HIGH);// set mmc0-cmd to high.
                gpio_direction_output(GPIO3B_GPIO3B2,GPIO_HIGH);//set mmc0-data0 to high.
                gpio_direction_output(GPIO3B_GPIO3B3,GPIO_HIGH);//set mmc0-data1 to high.
                gpio_direction_output(GPIO3B_GPIO3B4,GPIO_HIGH);//set mmc0-data2 to high.
                gpio_direction_output(GPIO3B_GPIO3B5,GPIO_HIGH);//set mmc0-data3 to high.

                mdelay(30);
            }
            else
            {	pr_info("daca pe mmc0 oprit");
                rk30_mux_api_set(GPIO3B0_SDMMC0CLKOUT_NAME, GPIO3B_GPIO3B0);
                gpio_request(RK30_PIN3_PB0, "mmc0-clk");
                gpio_direction_output(RK30_PIN3_PB0,GPIO_LOW);//set mmc0-clk to low.

                rk30_mux_api_set(GPIO3B1_SDMMC0CMD_NAME, GPIO3B_GPIO3B1);
                gpio_request(RK30_PIN3_PB1, "mmc0-cmd");
                gpio_direction_output(RK30_PIN3_PB1,GPIO_LOW);//set mmc0-cmd to low.

                rk30_mux_api_set(GPIO3B2_SDMMC0DATA0_NAME, GPIO3B_GPIO3B2);
                gpio_request(RK30_PIN3_PB2, "mmc0-data0");
                gpio_direction_output(RK30_PIN3_PB2,GPIO_LOW);//set mmc0-data0 to low.

                rk30_mux_api_set(GPIO3B3_SDMMC0DATA1_NAME, GPIO3B_GPIO3B3);
                gpio_request(RK30_PIN3_PB3, "mmc0-data1");
                gpio_direction_output(RK30_PIN3_PB3,GPIO_LOW);//set mmc0-data1 to low.

                rk30_mux_api_set(GPIO3B4_SDMMC0DATA2_NAME, GPIO3B_GPIO3B4);
                gpio_request(RK30_PIN3_PB4, "mmc0-data2");
                gpio_direction_output(RK30_PIN3_PB4,GPIO_LOW);//set mmc0-data2 to low.

                rk30_mux_api_set(GPIO3B5_SDMMC0DATA3_NAME, GPIO3B_GPIO3B5);
                gpio_request(RK30_PIN3_PB5, "mmc0-data3");
                gpio_direction_output(RK30_PIN3_PB5,GPIO_LOW);//set mmc0-data3 to low.

                mdelay(30);
            }
            #endif
        }
        break;
        
        case 1://mmc1
        {	 pr_info("am intrat la initializare pe mmc1");
            #ifdef CONFIG_SDMMC1_RK29
            if(on)
            {	pr_info("daca pe mmc1 pornit");
                gpio_direction_output(RK30_PIN3_PC5,GPIO_HIGH);//set mmc1-clk to high
                gpio_direction_output(RK30_PIN3_PC0,GPIO_HIGH);//set mmc1-cmd to high.
                gpio_direction_output(RK30_PIN3_PC1,GPIO_HIGH);//set mmc1-data0 to high.
                gpio_direction_output(RK30_PIN3_PC2,GPIO_HIGH);//set mmc1-data1 to high.
                gpio_direction_output(RK30_PIN3_PC3,GPIO_HIGH);//set mmc1-data2 to high.
                gpio_direction_output(RK30_PIN3_PC5,GPIO_HIGH);//set mmc1-data3 to high.//pus PIN3_PC4 mfd; era pc5 ca la clok
                mdelay(100);
            }
            else
            {	pr_info("daca pe mmc1 oprit");
                rk30_mux_api_set(GPIO3C5_SDMMC1CLKOUT_NAME, GPIO3C_GPIO3C5);
                gpio_request(RK30_PIN3_PC5, "mmc1-clk");
                gpio_direction_output(RK30_PIN3_PC5,GPIO_LOW);//set mmc1-clk to low.

                rk30_mux_api_set(GPIO3C0_SMMC1CMD_NAME, GPIO3C_GPIO3C0);
                gpio_request(RK30_PIN3_PC0, "mmc1-cmd");
                gpio_direction_output(RK30_PIN3_PC0,GPIO_LOW);//set mmc1-cmd to low.

                rk30_mux_api_set(GPIO3C1_SDMMC1DATA0_NAME, GPIO3C_GPIO3C1);
                gpio_request(RK30_PIN3_PC1, "mmc1-data0");
                gpio_direction_output(RK30_PIN3_PC1,GPIO_LOW);//set mmc1-data0 to low.
            #if defined(CONFIG_WIFI_COMBO_MODULE_CONTROL_FUNC) //mmc1 cu combo?
                rk29_mux_api_set(GPIO3C2_SDMMC1DATA1_NAME, GPIO3C_GPIO3C2);
                gpio_request(RK30_PIN3_PC2, "mmc1-data1");
                gpio_direction_output(RK30_PIN3_PC2,GPIO_LOW);//set mmc1-data1 to low.

                rk29_mux_api_set(GPIO3C3_SDMMC1DATA2_NAME, GPIO3C_GPIO3C3);
                gpio_request(RK30_PIN3_PC3, "mmc1-data2");
                gpio_direction_output(RK30_PIN3_PC3,GPIO_LOW);//set mmc1-data2 to low.

                rk29_mux_api_set(GPIO3C4_SDMMC1DATA3_NAME, GPIO3C_GPIO3C4);
                gpio_request(RK30_PIN3_PC4, "mmc1-data3");
                gpio_direction_output(RK30_PIN3_PC4,GPIO_LOW);//set mmc1-data3 to low.
           #endif
                mdelay(100);
            }
		pr_info("am iesit din mmc1");
            #endif
        }
        break; 
        
        case 2: //mmc2
        break;
        
        default:
        break;
    }
}

static void rk29_sdmmc_set_iomux_mmc0(unsigned int bus_width)
{pr_info("am intrat pe bus mmc0???");
    switch (bus_width)
    {
        
    	case 1://SDMMC_CTYPE_4BIT:
    	{	pr_info("bus pe mmc0 - nu ar trebui sa vad mesajul");
        	rk30_mux_api_set(GPIO3B3_SDMMC0DATA1_NAME, GPIO3B_SDMMC0_DATA1);
        	rk30_mux_api_set(GPIO3B4_SDMMC0DATA2_NAME, GPIO3B_SDMMC0_DATA2);
        	rk30_mux_api_set(GPIO3B5_SDMMC0DATA3_NAME, GPIO3B_SDMMC0_DATA3);
    	}
    	break;

    	case 0x10000://SDMMC_CTYPE_8BIT:
    	    break;
    	case 0xFFFF: //gpio_reset
    	{
		pr_info("S-a primit reset pe bus");
            rk30_mux_api_set(GPIO3A7_SDMMC0PWREN_NAME, GPIO3A_GPIO3A7);
            gpio_request(RK30_PIN3_PA7,"sdmmc-power");
            gpio_direction_output(RK30_PIN3_PA7,GPIO_HIGH); //power-off

        #if 0 //replace the power control into rk29_sdmmc_set_ios(); modifyed by xbw at 2012-08-12
            rk29_sdmmc_gpio_open(0, 0);

            gpio_direction_output(RK30_PIN3_PA7,GPIO_LOW); //power-on

            rk29_sdmmc_gpio_open(0, 1);
          #endif  
    	}
    	break;

    	default: //case 0://SDMMC_CTYPE_1BIT:
        {	pr_info("sunt pe sdmc de 1 bit?Ceva cu mmc0 oricum");
        	rk30_mux_api_set(GPIO3B1_SDMMC0CMD_NAME, GPIO3B_SDMMC0_CMD);
        	rk30_mux_api_set(GPIO3B0_SDMMC0CLKOUT_NAME, GPIO3B_SDMMC0_CLKOUT);
        	rk30_mux_api_set(GPIO3B2_SDMMC0DATA0_NAME, GPIO3B_SDMMC0_DATA0);

            rk30_mux_api_set(GPIO3B3_SDMMC0DATA1_NAME, GPIO3B_GPIO3B3);
            gpio_request(RK30_PIN3_PB3, "mmc0-data1");
            gpio_direction_output(RK30_PIN3_PB3,GPIO_HIGH);//set mmc0-data1 to high.

            rk30_mux_api_set(GPIO3B4_SDMMC0DATA2_NAME, GPIO3B_GPIO3B4);
            gpio_request(RK30_PIN3_PB4, "mmc0-data2");
            gpio_direction_output(RK30_PIN3_PB4,GPIO_HIGH);//set mmc0-data2 to high.

            rk30_mux_api_set(GPIO3B5_SDMMC0DATA3_NAME, GPIO3B_GPIO3B5);
            gpio_request(RK30_PIN3_PB5, "mmc0-data3");
            gpio_direction_output(RK30_PIN3_PB5,GPIO_HIGH);//set mmc0-data3 to high.
    	}
    	break;
	}
}

static void rk29_sdmmc_set_iomux_mmc1(unsigned int bus_width)
{pr_info("am intrat pe bus cu mmc1-ok trimit comenzi");
    rk30_mux_api_set(GPIO3C0_SMMC1CMD_NAME, GPIO3C_SMMC1_CMD);
    rk30_mux_api_set(GPIO3C5_SDMMC1CLKOUT_NAME, GPIO3C_SDMMC1_CLKOUT);
    rk30_mux_api_set(GPIO3C1_SDMMC1DATA0_NAME, GPIO3C_SDMMC1_DATA0);
    rk30_mux_api_set(GPIO3C2_SDMMC1DATA1_NAME, GPIO3C_SDMMC1_DATA1);
    rk30_mux_api_set(GPIO3C3_SDMMC1DATA2_NAME, GPIO3C_SDMMC1_DATA2);
    rk30_mux_api_set(GPIO3C4_SDMMC1DATA3_NAME, GPIO3C_SDMMC1_DATA3);
}

static void rk29_sdmmc_set_iomux_mmc2(unsigned int bus_width)
{
    ;//
}

static void rk29_sdmmc_set_iomux(int device_id, unsigned int bus_width)
{
    switch(device_id)
    {
        case 0:
            #ifdef CONFIG_SDMMC0_RK29
            rk29_sdmmc_set_iomux_mmc0(bus_width);
            #endif
            break;
        case 1:
            #ifdef CONFIG_SDMMC1_RK29
            rk29_sdmmc_set_iomux_mmc1(bus_width);
            #endif
            break;
        case 2:
            rk29_sdmmc_set_iomux_mmc2(bus_width);
            break;
        default:
            break;
    }    
}

#endif

static int rk29sdk_wifi_status(struct device *dev);
static int rk29sdk_wifi_status_register(void (*callback)(int card_presend, void *dev_id), void *dev_id);

#if defined(CONFIG_WIFI_COMBO_MODULE_CONTROL_FUNC)
static int rk29sdk_wifi_mmc0_status(struct device *dev);
static int rk29sdk_wifi_mmc0_status_register(void (*callback)(int card_presend, void *dev_id), void *dev_id);
static int rk29sdk_wifi_mmc0_cd = 0;   /* wifi virtual 'card detect' status */
static void (*wifi_mmc0_status_cb)(int card_present, void *dev_id);
static void *wifi_mmc0_status_cb_devid;
pr_info("am intrat pe la combo de ce???");
int rk29sdk_wifi_power_state = 0;
int rk29sdk_bt_power_state = 0;
#endif

static int rk29sdk_wifi_cd = 0;   /* wifi virtual 'card detect' status */
static void (*wifi_status_cb)(int card_present, void *dev_id);
static void *wifi_status_cb_devid;

#ifdef CONFIG_WIFI_CONTROL_FUNC

//
// Define wifi module's power and reset gpio, and gpio sensitive level 
//

#if defined(CONFIG_RK903) || defined(CONFIG_RK901)
#define RK30SDK_WIFI_GPIO_POWER_N       RK30_PIN3_PD0
#define RK30SDK_WIFI_GPIO_POWER_ENABLE_VALUE GPIO_HIGH //
#endif

#if defined(CONFIG_RTL8192CU) || defined(CONFIG_RTL8188EU) 
#define RK30SDK_WIFI_GPIO_POWER_N       RK30_PIN3_PD0
#define RK30SDK_WIFI_GPIO_POWER_ENABLE_VALUE GPIO_LOW 
#endif

#if defined(CONFIG_BCM4329) || defined(CONFIG_BCM4319) 
#define RK30SDK_WIFI_GPIO_POWER_N       RK30_PIN3_PD0
#define RK30SDK_WIFI_GPIO_POWER_ENABLE_VALUE GPIO_HIGH 
#define RK30SDK_WIFI_GPIO_RESET_N       RK30_PIN3_PD1
#define RK30SDK_WIFI_GPIO_RESET_ENABLE_VALUE GPIO_HIGH 
#endif

#define PREALLOC_WLAN_SEC_NUM           4
#define PREALLOC_WLAN_BUF_NUM           160
#define PREALLOC_WLAN_SECTION_HEADER    24

#define WLAN_SECTION_SIZE_0     (PREALLOC_WLAN_BUF_NUM * 128)
#define WLAN_SECTION_SIZE_1     (PREALLOC_WLAN_BUF_NUM * 128)
#define WLAN_SECTION_SIZE_2     (PREALLOC_WLAN_BUF_NUM * 512)
#define WLAN_SECTION_SIZE_3     (PREALLOC_WLAN_BUF_NUM * 1024)

#define WLAN_SKB_BUF_NUM        16

static struct sk_buff *wlan_static_skb[WLAN_SKB_BUF_NUM];

struct wifi_mem_prealloc {
        void *mem_ptr;
        unsigned long size;
};

static struct wifi_mem_prealloc wifi_mem_array[PREALLOC_WLAN_SEC_NUM] = {
        {NULL, (WLAN_SECTION_SIZE_0 + PREALLOC_WLAN_SECTION_HEADER)},
        {NULL, (WLAN_SECTION_SIZE_1 + PREALLOC_WLAN_SECTION_HEADER)},
        {NULL, (WLAN_SECTION_SIZE_2 + PREALLOC_WLAN_SECTION_HEADER)},
        {NULL, (WLAN_SECTION_SIZE_3 + PREALLOC_WLAN_SECTION_HEADER)}
};

static void *rk29sdk_mem_prealloc(int section, unsigned long size)
{
        if (section == PREALLOC_WLAN_SEC_NUM)
                return wlan_static_skb;

        if ((section < 0) || (section > PREALLOC_WLAN_SEC_NUM))
                return NULL;

        if (wifi_mem_array[section].size < size)
                return NULL;

        return wifi_mem_array[section].mem_ptr;
}

static int __init rk29sdk_init_wifi_mem(void)
{
        int i;
        int j;

        for (i = 0 ; i < WLAN_SKB_BUF_NUM ; i++) {
                wlan_static_skb[i] = dev_alloc_skb(
                                ((i < (WLAN_SKB_BUF_NUM / 2)) ? 4096 : 8192));

                if (!wlan_static_skb[i])
                        goto err_skb_alloc;
        }

        for (i = 0 ; i < PREALLOC_WLAN_SEC_NUM ; i++) {
                wifi_mem_array[i].mem_ptr =
                                kmalloc(wifi_mem_array[i].size, GFP_KERNEL);

                if (!wifi_mem_array[i].mem_ptr)
                        goto err_mem_alloc;
        }
        return 0;

err_mem_alloc:
        pr_err("Failed to mem_alloc for WLAN\n");
        for (j = 0 ; j < i ; j++)
               kfree(wifi_mem_array[j].mem_ptr);

        i = WLAN_SKB_BUF_NUM;

err_skb_alloc:
        pr_err("Failed to skb_alloc for WLAN\n");
        for (j = 0 ; j < i ; j++)
                dev_kfree_skb(wlan_static_skb[j]);

        return -ENOMEM;
}

static int rk29sdk_wifi_status(struct device *dev)
{	//pr_info("La prima trecere: %n",&rk29sdk_wifi_cd);
        return rk29sdk_wifi_cd; 
}

static int rk29sdk_wifi_status_register(void (*callback)(int card_present, void *dev_id), void *dev_id)
{	pr_info("La register raspund tot cu COMBO??");
        if(wifi_status_cb)
                return -EAGAIN;
        wifi_status_cb = callback;
        wifi_status_cb_devid = dev_id;
        return 0;
}

static int __init rk29sdk_wifi_bt_gpio_control_init(void)
{	pr_info("Initializare BT?");
    rk29sdk_init_wifi_mem();
    
    rk29_mux_api_set(GPIO3D0_SDMMC1PWREN_NAME, GPIO3D_GPIO3D0);
    
    if (gpio_request(RK30SDK_WIFI_GPIO_POWER_N, "wifi_power")) {
           pr_info("%s: request wifi power gpio failed\n", __func__);
           return -1;
    }
/*
#ifdef RK30SDK_WIFI_GPIO_RESET_N
    if (gpio_request(RK30SDK_WIFI_GPIO_RESET_N, "wifi reset")) {
           pr_info("%s: request wifi reset gpio failed\n", __func__);
           gpio_free(RK30SDK_WIFI_GPIO_POWER_N);
           return -1;
    }
#endif    
*/
    gpio_direction_output(RK30SDK_WIFI_GPIO_POWER_N, GPIO_LOW);//!RK30SDK_WIFI_GPIO_POWER_ENABLE_VALUE);
/*
#ifdef RK30SDK_WIFI_GPIO_RESET_N    
    gpio_direction_output(RK30SDK_WIFI_GPIO_RESET_N, !RK30SDK_WIFI_GPIO_RESET_ENABLE_VALUE);
#endif    
*/
    #if defined(CONFIG_SDMMC1_RK29) && !defined(CONFIG_SDMMC_RK29_OLD)
    pr_info("Setare comunicate BT?");
    rk29_mux_api_set(GPIO3C2_SDMMC1DATA1_NAME, GPIO3C_GPIO3C2);
    gpio_request(RK30_PIN3_PC2, "mmc1-data1");
    gpio_direction_output(RK30_PIN3_PC2,GPIO_LOW);//set mmc1-data1 to low.

    rk29_mux_api_set(GPIO3C3_SDMMC1DATA2_NAME, GPIO3C_GPIO3C3);
    gpio_request(RK30_PIN3_PC3, "mmc1-data2");
    gpio_direction_output(RK30_PIN3_PC3,GPIO_LOW);//set mmc1-data2 to low.

    rk29_mux_api_set(GPIO3C4_SDMMC1DATA3_NAME, GPIO3C_GPIO3C4);
    gpio_request(RK30_PIN3_PC4, "mmc1-data3");
    gpio_direction_output(RK30_PIN3_PC4,GPIO_LOW);//set mmc1-data3 to low.
    
    rk29_sdmmc_gpio_open(1, 0); //added by xbw at 2011-10-13
    #endif    
    pr_info("TErminat wifi_bt %s: init finished\n",__func__);

    return 0;
}

int rk29sdk_wifi_power(int on)
{
        pr_info("Pornesc puterea: %s: %d\n", __func__, on);
        if (on){
                gpio_set_value(RK30SDK_WIFI_GPIO_POWER_N,  GPIO_HIGH);//RK30SDK_WIFI_GPIO_POWER_ENABLE_VALUE);

                #if defined(CONFIG_SDMMC1_RK29) && !defined(CONFIG_SDMMC_RK29_OLD)	
		pr_info("Apel gpio_open()");
                rk29_sdmmc_gpio_open(1, 1); //added by xbw at 2011-10-13
                #endif
/*
#ifdef RK30SDK_WIFI_GPIO_RESET_N
                gpio_set_value(RK30SDK_WIFI_GPIO_RESET_N, RK30SDK_WIFI_GPIO_RESET_ENABLE_VALUE);
#endif                
*/
                mdelay(100);
                pr_info("Mihai wifi turn on power\n");
        }else{
//                if (!rk29sdk_bt_power_state){
                        gpio_set_value(RK30SDK_WIFI_GPIO_POWER_N, GPIO_LOW);// !RK30SDK_WIFI_GPIO_POWER_ENABLE_VALUE);
			pr_info("Apel inchidere. De unde???");
                        #if defined(CONFIG_SDMMC1_RK29) && !defined(CONFIG_SDMMC_RK29_OLD)	
                        rk29_sdmmc_gpio_open(1, 0); //added by xbw at 2011-10-13
                        #endif
                        
                        mdelay(100);
                        pr_info("Aci opri! wifi shut off power\n");
//                }else
//                {
//                        pr_info("wifi shouldn't shut off power, bt is using it!\n");
//                }
/*
#ifdef RK30SDK_WIFI_GPIO_RESET_N
                gpio_set_value(RK30SDK_WIFI_GPIO_RESET_N, !RK30SDK_WIFI_GPIO_RESET_ENABLE_VALUE);
#endif 
*/
        }

//        rk29sdk_wifi_power_state = on;
        return 0;
}
//EXPORT_SYMBOL(rk29sdk_wifi_power);//mfd

static int rk29sdk_wifi_reset_state;
static int rk29sdk_wifi_reset(int on)
{
        pr_info("Facem un reset??: %s: %d\n", __func__, on);
        //mdelay(100);
        rk29sdk_wifi_reset_state = on;
        return 0;
}

int rk29sdk_wifi_set_carddetect(int val)
{
        pr_info("Incep detectare card: %s:%d\n", __func__, val);
        rk29sdk_wifi_cd = val;
        if (wifi_status_cb){
                wifi_status_cb(val, wifi_status_cb_devid);
        }else {
                pr_warning("%s, nobody to notify\n", __func__);
        }
        return 0;
}
EXPORT_SYMBOL(rk29sdk_wifi_set_carddetect);

#define WIFI_HOST_WAKE RK30_PIN6_PA7//RK30_PIN3_PD2 //mfd schimbat dupa mk808

static struct resource resources[] = {
	{
		.start = WIFI_HOST_WAKE,
		.flags = IORESOURCE_IRQ,
		.name = "bcmdhd_wlan_irq",
	},
};


///////////////////////////////////////////////////////////////////////////////////
#elif defined(CONFIG_WIFI_COMBO_MODULE_CONTROL_FUNC)
#if defined(CONFIG_MACH_RK30_PHONE_PAD)
   #if defined(CONFIG_USE_SDMMC0_FOR_WIFI_DEVELOP_BOARD)
   #define USE_SDMMC_CONTROLLER_FOR_WIFI 0
   #define RK29SDK_WIFI_COMBO_GPIO_POWER_N	RK30_PIN4_PD2
   #define RK29SDK_WIFI_COMBO_GPIO_RESET_N	RK30_PIN4_PD1
   #define RK29SDK_WIFI_COMBO_GPIO_VDDIO	RK30_PIN1_PA6	
   #define RK29SDK_WIFI_COMBO_GPIO_BGF_INT_B	RK30_PIN1_PA7	 
   #define RK29SDK_WIFI_COMBO_GPS_SYNC		RK30_PIN3_PC7	 
       
   #else
   #define USE_SDMMC_CONTROLLER_FOR_WIFI 1
   #define RK29SDK_WIFI_COMBO_GPIO_POWER_N	RK30_PIN3_PC7	
   #define RK29SDK_WIFI_COMBO_GPIO_RESET_N	RK30_PIN3_PD1	
   #define RK29SDK_WIFI_COMBO_GPIO_WIFI_INT_B	RK30_PIN3_PD2
       
   //#define RK29SDK_WIFI_COMBO_GPIO_VDDIO	      RK30_PIN6_PB4   
   #define RK29SDK_WIFI_COMBO_GPIO_BGF_INT_B	RK30_PIN6_PA7	 
   #define RK29SDK_WIFI_COMBO_GPS_SYNC		RK30_PIN3_PD0	 
   #endif
#else

    #if defined(CONFIG_USE_SDMMC0_FOR_WIFI_DEVELOP_BOARD)
    #define USE_SDMMC_CONTROLLER_FOR_WIFI 0
    #define RK29SDK_WIFI_COMBO_GPIO_POWER_N      RK30_PIN4_PD2
    #define RK29SDK_WIFI_COMBO_GPIO_RESET_N      RK30_PIN4_PD1
    #define RK29SDK_WIFI_COMBO_GPIO_VDDIO        RK30_PIN1_PA6   
    #define RK29SDK_WIFI_COMBO_GPIO_BGF_INT_B    RK30_PIN1_PA7    
    #define RK29SDK_WIFI_COMBO_GPS_SYNC          RK30_PIN3_PC7    
    
    #else
    #define USE_SDMMC_CONTROLLER_FOR_WIFI 1
    #define RK29SDK_WIFI_COMBO_GPIO_POWER_N      RK30_PIN3_PD0   
    #define RK29SDK_WIFI_COMBO_GPIO_RESET_N      RK30_PIN3_PD1   
    #define RK29SDK_WIFI_COMBO_GPIO_WIFI_INT_B   RK30_PIN3_PD2
    
    #define RK29SDK_WIFI_COMBO_GPIO_VDDIO        RK30_PIN6_PB4   
    #define RK29SDK_WIFI_COMBO_GPIO_BGF_INT_B    RK30_PIN3_PC6    
    #define RK29SDK_WIFI_COMBO_GPS_SYNC          RK30_PIN3_PC7    
    #endif
#endif

#define debug_combo_system 0

int rk29sdk_wifi_combo_get_BGFgpio(void)
{
    return RK29SDK_WIFI_COMBO_GPIO_BGF_INT_B;
}
EXPORT_SYMBOL(rk29sdk_wifi_combo_get_BGFgpio);


int rk29sdk_wifi_combo_get_GPS_SYNC_gpio(void)
{
    return RK29SDK_WIFI_COMBO_GPS_SYNC;
}
EXPORT_SYMBOL(rk29sdk_wifi_combo_get_GPS_SYNC_gpio);


static int rk29sdk_wifi_combo_module_gpio_init(void)
{        
    if (gpio_request(RK29SDK_WIFI_COMBO_GPIO_RESET_N, "combo-RST"))
    {
        pr_info("%s:request combo-RST failed\n", __func__);
        return -1;
    }
    gpio_direction_output(RK29SDK_WIFI_COMBO_GPIO_RESET_N, GPIO_LOW);

    if (gpio_request(RK29SDK_WIFI_COMBO_GPIO_POWER_N, "combo-PMUEN"))
	{
		pr_info("%s:request combo-PMUEN failed\n", __func__);
		return -1;
	}
	
	//gpio_pull_updown(RK29SDK_WIFI_COMBO_GPIO_POWER_N,0);
	//gpio_direction_input(RK29SDK_WIFI_COMBO_GPIO_POWER_N);
	gpio_direction_output(RK29SDK_WIFI_COMBO_GPIO_POWER_N, GPIO_LOW);
    return 0;
}


int rk29sdk_wifi_combo_module_power(int on)
{
     if(on)
    {
        //gpio_set_value(RK29SDK_WIFI_COMBO_GPIO_VDDIO, GPIO_HIGH);
        //mdelay(10);
        gpio_set_value(RK29SDK_WIFI_COMBO_GPIO_POWER_N, GPIO_HIGH);     
        mdelay(10);
        pr_info("combo-module turn on power\n");
    }
    else
    {
        gpio_set_value(RK29SDK_WIFI_COMBO_GPIO_POWER_N, GPIO_LOW);        
        mdelay(10);
        //gpio_set_value(RK29SDK_WIFI_COMBO_GPIO_VDDIO, GPIO_LOW);
        pr_info("combo-module turn off power\n");
    }
     return 0;
    
}
EXPORT_SYMBOL(rk29sdk_wifi_combo_module_power);


int rk29sdk_wifi_combo_module_reset(int on)
{
    if(on)
    {
        gpio_set_value(RK29SDK_WIFI_COMBO_GPIO_RESET_N, GPIO_HIGH);     
        pr_info("combo-module reset out 1\n");
    }
    else
    {
        gpio_set_value(RK29SDK_WIFI_COMBO_GPIO_RESET_N, GPIO_LOW);        
        pr_info("combo-module  reset out 0\n");
    }

    return 0;   
}
EXPORT_SYMBOL(rk29sdk_wifi_combo_module_reset);


static int rk29sdk_wifi_mmc0_status(struct device *dev)
{
        return rk29sdk_wifi_mmc0_cd;
}

static int rk29sdk_wifi_mmc0_status_register(void (*callback)(int card_present, void *dev_id), void *dev_id)
{
        if(wifi_mmc0_status_cb)
                return -EAGAIN;
        wifi_mmc0_status_cb = callback;
        wifi_mmc0_status_cb_devid = dev_id;
        return 0;
}


static int rk29sdk_wifi_status(struct device *dev)
{
        return rk29sdk_wifi_cd;
}

static int rk29sdk_wifi_status_register(void (*callback)(int card_present, void *dev_id), void *dev_id)
{
        if(wifi_status_cb)
                return -EAGAIN;
        wifi_status_cb = callback;
        wifi_status_cb_devid = dev_id;
        return 0;
}
extern unsigned int sdio_irq_global;

int rk29sdk_wifi_power(int on)
{
    pr_info("%s: %d\n", __func__, on);
    if (on){
    
        #if defined(CONFIG_SDMMC1_RK29) && !defined(CONFIG_SDMMC_RK29_OLD)  
            
          #if defined(CONFIG_USE_SDMMC0_FOR_WIFI_DEVELOP_BOARD)
             rk29_sdmmc_gpio_open(0, 1); 
          #else
            rk29_sdmmc_gpio_open(1, 0);                
            mdelay(10);
            rk29_sdmmc_gpio_open(1, 1); 
          #endif 
        #endif
    
            mdelay(100);
            pr_info("wifi turn on power\n");
    }
    else
    {    
#if defined(CONFIG_SDMMC1_RK29) && !defined(CONFIG_SDMMC_RK29_OLD)
        #if defined(CONFIG_USE_SDMMC0_FOR_WIFI_DEVELOP_BOARD)
        rk29_sdmmc_gpio_open(0, 0);
        #else
        rk29_sdmmc_gpio_open(1, 0);
        #endif
#endif      
        mdelay(100);
        pr_info("wifi shut off power\n");
         
    }
    
    rk29sdk_wifi_power_state = on;
    return 0;

}
EXPORT_SYMBOL(rk29sdk_wifi_power);


int rk29sdk_wifi_reset(int on)
{    
    return 0;
}
EXPORT_SYMBOL(rk29sdk_wifi_reset);


#if defined(CONFIG_USE_SDMMC0_FOR_WIFI_DEVELOP_BOARD)
int rk29sdk_wifi_set_carddetect(int val)
{
    pr_info("%s:%d\n", __func__, val);
    rk29sdk_wifi_mmc0_cd = val;
    if (wifi_mmc0_status_cb){
            wifi_mmc0_status_cb(val, wifi_mmc0_status_cb_devid);
    }else {
            pr_warning("%s,in mmc0 nobody to notify\n", __func__);
    }
    return 0; 
}

#else
int rk29sdk_wifi_set_carddetect(int val)
{
    pr_info("%s:%d\n", __func__, val);
    rk29sdk_wifi_cd = val;
    if (wifi_status_cb){
            wifi_status_cb(val, wifi_status_cb_devid);
    }else {
            pr_warning("%s,in mmc1 nobody to notify\n", __func__);
    }
    return 0; 
}
#endif

EXPORT_SYMBOL(rk29sdk_wifi_set_carddetect);

#endif  ///  #endif ---#elif defined(CONFIG_WIFI_COMBO_MODULE_CONTROL_FUNC)



#if defined(CONFIG_WIFI_CONTROL_FUNC)
static struct wifi_platform_data rk29sdk_wifi_control = {
        .set_power = rk29sdk_wifi_power,
        .set_reset = rk29sdk_wifi_reset,
        .set_carddetect = rk29sdk_wifi_set_carddetect,
        .mem_prealloc   = rk29sdk_mem_prealloc,
};

static struct platform_device rk29sdk_wifi_device = {
        .name = "bcmdhd_wlan",
        .id = 1,
        .num_resources = ARRAY_SIZE(resources),
        .resource = resources,
        .dev = {
                .platform_data = &rk29sdk_wifi_control,
         },
};

#elif defined(CONFIG_WIFI_COMBO_MODULE_CONTROL_FUNC)

    #if debug_combo_system
        static struct combo_module_platform_data rk29sdk_combo_module_control = {
            .set_power = rk29sdk_wifi_combo_module_power,
            .set_reset = rk29sdk_wifi_combo_module_reset,  
        };

        static struct platform_device  rk29sdk_combo_module_device = {
                .name = "combo-system",
                .id = 1,
                .dev = {
                        .platform_data = &rk29sdk_combo_module_control,
                 },
        };
    #endif

static struct wifi_platform_data rk29sdk_wifi_control = {
        .set_power = rk29sdk_wifi_power,
        .set_reset = rk29sdk_wifi_reset,
        .set_carddetect = rk29sdk_wifi_set_carddetect,
};

static struct platform_device rk29sdk_wifi_device = {
        .name = "combo-wifi",
        .id = 1,
        .dev = {
                .platform_data = &rk29sdk_wifi_control,
         },
};

#endif


#endif // endif --#ifdef CONFIG_SDMMC_RK29

