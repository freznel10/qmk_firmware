// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project


#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"

uint32_t LV_EVENT_GET_COMP_CHILD;

typedef struct {
    uint32_t child_idx;
    lv_obj_t * child;
} ui_comp_get_child_t;

lv_obj_t * ui_comp_get_child(lv_obj_t * comp, uint32_t child_idx)
{
    ui_comp_get_child_t info;
    info.child = NULL;
    info.child_idx = child_idx;
    lv_event_send(comp, LV_EVENT_GET_COMP_CHILD, &info);
    return info.child;
}

void get_component_child_event_cb(lv_event_t * e)
{
    lv_obj_t ** c = lv_event_get_user_data(e);
    ui_comp_get_child_t * info = lv_event_get_param(e);
    info->child = c[info->child_idx];
}

void del_component_child_event_cb(lv_event_t * e)
{
    lv_obj_t ** c = lv_event_get_user_data(e);
    lv_mem_free(c);
}


// COMPONENT Chart1

lv_obj_t * ui_Chart1_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Chart1;
    cui_Chart1 = lv_chart_create(comp_parent);
    lv_obj_set_width(cui_Chart1, 180);
    lv_obj_set_height(cui_Chart1, 100);
    lv_obj_set_x(cui_Chart1, 3);
    lv_obj_set_y(cui_Chart1, 61);
    lv_obj_set_align(cui_Chart1, LV_ALIGN_CENTER);

    lv_obj_set_style_line_color(cui_Chart1, lv_color_hex(0x4040FF), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(cui_Chart1, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(cui_Chart1, lv_color_hex(0x4040FF), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(cui_Chart1, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(cui_Chart1, false, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(cui_Chart1, false, LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_CHART1_NUM);
    children[UI_COMP_CHART1_CHART1] = cui_Chart1;
    lv_obj_add_event_cb(cui_Chart1, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Chart1, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Chart1;
}



// COMPONENT WPM

lv_obj_t * ui_WPM_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_WPM;
    cui_WPM = lv_arc_create(comp_parent);
    lv_obj_set_width(cui_WPM, 150);
    lv_obj_set_height(cui_WPM, 150);
    lv_obj_set_align(cui_WPM, LV_ALIGN_CENTER);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_WPM_NUM);
    children[UI_COMP_WPM_WPM] = cui_WPM;
    lv_obj_add_event_cb(cui_WPM, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_WPM, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_WPM;
}

