/*
 * 
 *
 * Copyright (C) 2013 Huawei Inc.
 */


#ifndef __HISI_COUL_DRV_H
#define __HISI_COUL_DRV_H

#define	BAT_VOL_3500						(3500)
#define	BAT_VOL_3600						(3600)
#define	BAT_VOL_3700						(3700)
#define	BAT_VOL_3800						(3800)
#define	BAT_VOL_3900						(3900)

enum HISI_COULOMETER_TYPE {
    COUL_SMARTSTAR = 0,
    COUL_BQ27510,
    COUL_UNKNOW,
};

struct battery_charge_param_s{
    unsigned int      max_currentmA;
    unsigned int      max_voltagemV;
    unsigned int      max_cin_currentmA;
    unsigned int      charge_in_temp_5;
    unsigned int      charge_in_temp_10;
    unsigned int      design_capacity;
};

struct hisi_coul_ops {
    int (*is_coul_ready)(void);
    int (*is_battery_exist)(void);
    int (*is_battery_reach_threshold)(void);
    int (*is_battery_full)(void);
    char *(*battery_brand)(void);
    int (* battery_id_voltage)(void);
    int (*battery_voltage)(void);
    int (*battery_voltage_uv)(void);
    int (*battery_current)(void);
    int (*battery_current_avg)(void);
    int (*battery_unfiltered_capacity)(void);
    int (*battery_capacity)(void);
    int (*battery_uf_temperature)(void);
    int (*battery_temperature)(void);
    int (*battery_rm)(void);
    int (*battery_fcc)(void);
    int (*battery_tte)(void);
    int (*battery_ttf)(void);
    int (*battery_health)(void);
    int (*battery_capacity_level)(void);
    int (*battery_technology)(void);
    int (*battery_charge_param)(struct battery_charge_param_s *param);
    int (*charger_event_rcv)(unsigned int);
#ifdef CONFIG_HUAWEI_HLTHERM_CHARGING
    int (*is_hisi_coul_write)(int);
    int (*is_hisi_coul_read)(void);
#endif
};



extern enum HISI_COULOMETER_TYPE hisi_coulometer_type(void);
extern void hisi_coul_charger_event_rcv(unsigned int event);
extern int is_hisi_coul_ready(void);
extern int is_hisi_battery_exist(void);
extern int is_hisi_battery_reach_threshold(void);
extern int is_hisi_battery_full(void);
extern int hisi_battery_voltage(void);
extern char* hisi_battery_brand(void);
extern int hisi_battery_voltage_uv(void);
extern int hisi_battery_current(void);
extern int hisi_battery_current_avg(void);
extern int hisi_battery_unfiltered_capacity(void);
extern int hisi_battery_capacity(void);
extern int hisi_battery_uf_temperature(void);
extern int hisi_battery_temperature(void);
extern int hisi_battery_rm(void);
extern int hisi_battery_fcc(void);
extern int hisi_battery_tte(void);
extern int hisi_battery_ttf(void);
extern int hisi_battery_health(void);
extern int hisi_battery_capacity_level(void);
extern int hisi_battery_technology(void);
extern int hisi_battery_charge_param(struct battery_charge_param_s *param);
extern int hisi_coul_ops_register (struct hisi_coul_ops *coul_ops,enum HISI_COULOMETER_TYPE coul_type);
extern int hisi_coul_ops_unregister (struct hisi_coul_ops *coul_ops);
extern int hisi_power_supply_voltage(void);
extern int hisi_battery_id_voltage(void);
#ifdef CONFIG_HUAWEI_HLTHERM_CHARGING
extern int hisi_coul_reg_write(int temp);
extern int hisi_coul_reg_read(void);
#endif
#endif
