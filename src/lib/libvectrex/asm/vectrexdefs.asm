* this include file is a work-in-progress

print_str_d             EQU     $f37a
print_ships             EQU     $f393
print_at_d              EQU     $f37a
printu2                 EQU     $f38a
print_1_string          EQU     $f373

Init_Music_chk          EQU     $F687
init_music_buf          EQU     $f533
init_sound_chk          EQU     $f687
init_sound              EQU     $f68d
byte2sndchip            EQU     $F256
Do_Sound                EQU     $F289
sound_byte              EQU     $f256
sound_bytes             EQU     $f27d
copy2sndchip            EQU     $F27D

reset0ref               EQU     $f354
VIA_t1_cnt_lo           EQU     $D004
Vec_Music_Flag          EQU     $C856
Vec_Misc_Count          EQU     $C823
compare_scores          EQU     $f8c7
covert_add_bcd          EQU     $f85e
read_switches2          EQU     $f1ba
;get_pl_game             EQU     $f7a9
dptoC8                  EQU     $f1af
dptoD0                  EQU     $f1aa
read_switches           EQU     $f1b4
read_joystick           EQU     $f1f8

clear_256_bytes         EQU     $f545
set_dft_score           EQU     $f84f
rot_vec_list2           EQU     $f610
display_string          EQU     $f495
conv_ang_rr             EQU     $F601
get_abs_val_ab          EQU     $F584
rot_vec_list1           EQU     $f61f
joy_analog              EQU     $f1f5
random                  EQU     $f511
clear_score             EQU     $f84f
add_score_a             EQU     $f85e
add_score_d             EQU     $f87c
new_high_score          EQU     $f8d8
obj_hit                 EQU     $f8ff
;explosion_snd           EQU     $f92e
;do_sound                EQU     $f289
;clear_sound             EQU     $f272

* Vectrex system equates

waitrecal	equ	$f192

draw_vl_count4          EQU     $f3ce
draw_vl_a               EQU     $f3da
drawl1b                 EQU     $f40e
draw_to_d               EQU     $f3df
draw_to_d               EQU     $f3df

dot_at_d                EQU     $f2c3
dot_ix                  EQU     $f2c1
dot_d                   EQU     $f2c3
dot_here                EQU     $f2c5

move_draw_VL4	equ	$f3b7
move_pen7f_to_d	equ	$f2fc
moveto_d_7f             EQU     $F2FC
move_block              EQU     $f67f
move_block2             EQU     $f683
move_penff              EQU     $f308
move_pen7f              EQU     $f30c
move_pen                EQU     $f310
move_pen_d              EQU     $f312
move_draw_VL4           EQU     $f3b7

intensity_to_1f         EQU     $f29d
intensity_to_3f         EQU     $f2a1
intensity_to_5f         EQU     $f2a5
intensity_to_7f         EQU     $f2a9
intensity_to_A	equ	$f2ab
intensity_to_A          EQU     $f2ab
intensity_to_A          EQU     $f2ab

BIOS_music_data         EQU     $FC8D
BIOS_music_data         EQU     $FC8D
