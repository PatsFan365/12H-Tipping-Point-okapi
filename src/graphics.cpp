#include "main.h"

/*
btn key
0 = right
1 = left
2 = half win point right
3 = half win point left
4 = winpoint right
5 = winpoint left
6 = skills
*/

lv_obj_t * redRightAutonBtn;
lv_obj_t * redRightAutonLabel;
lv_obj_t * redLeftAutonBtn;
lv_obj_t * redLeftAutonLabel;
lv_obj_t * blueRightAutonBtn;
lv_obj_t * blueRightAutonLabel;
lv_obj_t * blueLeftAutonBtn;
lv_obj_t * blueLeftAutonLabel;
lv_obj_t * rightWinPointBtn;
lv_obj_t * rightWinPointLabel;
lv_obj_t * leftWinPointBtn;
lv_obj_t * leftWinPointLabel;
lv_obj_t * skillsBtn;
lv_obj_t * skillsLabel;
lv_obj_t * title;
lv_obj_t * currentAutonLabel;

lv_style_t redStyleReleased;
lv_style_t redStylePressed;
lv_style_t blueStyleReleased;
lv_style_t blueStylePressed;
lv_style_t winPointStyleReleased;
lv_style_t winPointStylePressed;
lv_style_t skillsStyleReleased;
lv_style_t skillsStylePressed;

std::string currentAuton;

static lv_res_t btnClicked(lv_obj_t * btn){
    if(autonNumSelect != lv_obj_get_free_num(btn)){
        autonNumSelect = lv_obj_get_free_num(btn); // change current auton number
        switch(autonNumSelect) { //set auton name based on chosen button
            case 0:
                currentAuton = "current auton: right";
                break;
            case 1:
                currentAuton = "current auton: left";
                break;
            case 2:
                currentAuton = "current auton: half win point right";
                break;
            case 3:
                currentAuton = "current auton: half winpoint left";
                break;
            case 4:
                currentAuton = "current auton: win-point right";
                break;
            case 5:
                currentAuton = "current auton: win-point left";
                break;
            case 6:
                currentAuton = "current auton: skills";
                break;
        }
        lv_label_set_text(currentAutonLabel, currentAuton.c_str());
    }
    return LV_RES_OK;
}

lv_obj_t * createBtn(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height,
    int id, const char * title)
{
    lv_obj_t * btn = lv_btn_create(parent, NULL);
    lv_obj_set_pos(btn, x, y);
    lv_obj_set_size(btn, width, height);
    lv_obj_set_free_num(btn, id);

    lv_obj_t * label = lv_label_create(btn, NULL);
    lv_label_set_text(label, title);
    lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 5);

    return btn;
}
lv_style_t * createBtnStyle(lv_style_t * copy, lv_color_t rel, lv_color_t pr,
    lv_color_t tglRel, lv_color_t tglPr, lv_color_t tglBorder, lv_color_t textColor, lv_obj_t * btn)
{
    lv_style_t * btnStyle = (lv_style_t *)malloc(sizeof(lv_style_t) * 4);

    for(int i = 0; i < 4; i++) lv_style_copy(&btnStyle[i], copy);

    btnStyle[0].body.main_color = rel;
    btnStyle[0].body.grad_color = rel;
    btnStyle[0].text.color = textColor;

    btnStyle[1].body.main_color = pr;
    btnStyle[1].body.grad_color = pr;
    btnStyle[1].text.color = textColor;

    btnStyle[2].body.main_color = tglRel;
    btnStyle[2].body.grad_color = tglRel;
    btnStyle[2].body.border.width = 2;
    btnStyle[2].body.border.color = tglBorder;
    btnStyle[2].text.color = textColor;

    btnStyle[3].body.main_color = tglPr;
    btnStyle[3].body.grad_color = tglPr;
    btnStyle[3].body.border.width = 2;
    btnStyle[3].body.border.color = tglBorder;
    btnStyle[3].text.color = textColor;

    lv_btn_set_style(btn, LV_BTN_STYLE_REL, &btnStyle[0]);
    lv_btn_set_style(btn, LV_BTN_STYLE_PR, &btnStyle[1]);
    lv_btn_set_style(btn, LV_BTN_STYLE_TGL_REL, &btnStyle[2]);
    lv_btn_set_style(btn, LV_BTN_STYLE_TGL_PR, &btnStyle[3]);

    return btnStyle;
}
void setBtnStyle(lv_style_t * btnStyle, lv_obj_t * btn)
{
    lv_btn_set_style(btn, LV_BTN_STYLE_REL, &btnStyle[0]);
    lv_btn_set_style(btn, LV_BTN_STYLE_PR, &btnStyle[1]);
    lv_btn_set_style(btn, LV_BTN_STYLE_TGL_REL, &btnStyle[2]);
    lv_btn_set_style(btn, LV_BTN_STYLE_TGL_PR, &btnStyle[3]);
}

void autonSelectScreen(){
    //color pallate: https://coolors.co/0e72df-031d44-efcefa-990d35-131b23
    //create title label
    title = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(title, "Auton selector");
    lv_obj_align(title, NULL, LV_ALIGN_IN_TOP_MID, 0, 10);

    currentAutonLabel = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(currentAutonLabel, "No Auton Selected");
    lv_obj_align(currentAutonLabel, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -10);

    //create button styles
    lv_style_copy(&redStylePressed, &lv_style_plain);
    redStylePressed.body.main_color = LV_COLOR_MAKE(115, 10, 40);
    redStylePressed.body.grad_color = LV_COLOR_MAKE(115, 10, 40); //maybe inverse of first main color
    redStylePressed.body.radius = 0;
    redStylePressed.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&redStyleReleased, &lv_style_plain);
    redStyleReleased.body.main_color = LV_COLOR_MAKE(153, 13, 53);
    redStyleReleased.body.grad_color = LV_COLOR_MAKE(153, 13, 53); //maybe inverse of first main color
    redStyleReleased.body.radius = 0;
    redStyleReleased.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&blueStylePressed, &lv_style_plain);
    blueStylePressed.body.main_color = LV_COLOR_MAKE(11, 86, 167);
    blueStylePressed.body.grad_color = LV_COLOR_MAKE(11, 86, 167); //maybe inverse of first main color
    blueStylePressed.body.radius = 0;
    blueStylePressed.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&blueStyleReleased, &lv_style_plain);
    blueStyleReleased.body.main_color = LV_COLOR_MAKE(14, 114, 223);
    blueStyleReleased.body.grad_color = LV_COLOR_MAKE(14, 114, 223); //maybe inverse of first main color
    blueStyleReleased.body.radius = 0;
    blueStyleReleased.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&winPointStylePressed, &lv_style_plain);
    blueStylePressed.body.main_color = LV_COLOR_MAKE(153, 184, 129);
    blueStylePressed.body.grad_color = LV_COLOR_MAKE(153, 184, 129); //maybe inverse of first main color
    blueStylePressed.body.radius = 0;
    blueStylePressed.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&winPointStyleReleased, &lv_style_plain);
    blueStyleReleased.body.main_color = LV_COLOR_MAKE(204, 245, 172);
    blueStyleReleased.body.grad_color = LV_COLOR_MAKE(204, 245, 172); //maybe inverse of first main color
    blueStyleReleased.body.radius = 0;
    blueStyleReleased.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&skillsStylePressed, &lv_style_plain);
    skillsStylePressed.body.main_color = LV_COLOR_MAKE(179, 155, 188);
    skillsStylePressed.body.grad_color = LV_COLOR_MAKE(179, 155, 188); //maybe inverse of first main color
    skillsStylePressed.body.radius = 0;
    skillsStylePressed.text.color = LV_COLOR_MAKE(0, 0, 0);

    lv_style_copy(&skillsStyleReleased, &lv_style_plain);
    skillsStyleReleased.body.main_color = LV_COLOR_MAKE(239, 206, 250);
    skillsStyleReleased.body.grad_color = LV_COLOR_MAKE(239, 206, 250); //maybe inverse of first main color
    skillsStyleReleased.body.radius = 0;
    skillsStyleReleased.text.color = LV_COLOR_MAKE(0, 0, 0);

    redRightAutonBtn = createBtn(lv_scr_act(), 10, 50, 150, 83, 0, "Right");
    lv_btn_set_action(redRightAutonBtn, LV_BTN_ACTION_CLICK, btnClicked);
    redLeftAutonBtn = createBtn(lv_scr_act(), 165, 50, 150, 83, 1, "Left");
    lv_btn_set_action(redLeftAutonBtn, LV_BTN_ACTION_CLICK, btnClicked);
    skillsBtn = createBtn(lv_scr_act(), 320, 50, 150, 83, 6, "Skills");
    lv_btn_set_action(skillsBtn, LV_BTN_ACTION_CLICK, btnClicked);
    blueRightAutonBtn = createBtn(lv_scr_act(), 10, 139, 109, 83, 2, "half WP Right");
    lv_btn_set_action(blueRightAutonBtn, LV_BTN_ACTION_CLICK, btnClicked);
    blueLeftAutonBtn = createBtn(lv_scr_act(), 124, 139, 109, 83, 3, "half WP Left");
    lv_btn_set_action(blueLeftAutonBtn, LV_BTN_ACTION_CLICK, btnClicked);
    rightWinPointBtn = createBtn(lv_scr_act(), 241, 139, 109, 83, 4, "Right WP");
    lv_btn_set_action(rightWinPointBtn, LV_BTN_ACTION_CLICK, btnClicked);
    leftWinPointBtn = createBtn(lv_scr_act(), 359, 139, 109, 83, 5, "Left WP");
    lv_btn_set_action(leftWinPointBtn, LV_BTN_ACTION_CLICK, btnClicked);
}