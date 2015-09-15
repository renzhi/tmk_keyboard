/**
 * Copyright (C) 2015, xp@renzhi.ca, all rights reserverd.
 */

/**
 * Note: Dimension units are all in mm, except angle, which is in degrees.
 */

// Thickness of entire plate
plate_thickness = 3;
wall_thickeness = 10;
wall_height = 12;
plate_length = 340;
plate_width = 200;

bottom_left_x = -(plate_length / 2);
bottom_left_y = -(plate_width / 2);

//Radius of mounting screw holes
screw_hole_radius = 2;
// Distance of a screw from the edge
screw_dist_edge = 5;

pos_z = ((plate_thickness+wall_thickeness)/2) - (((plate_thickness+wall_thickeness)/2) - plate_thickness);

screw_holes = [
     // Starting at the bottom left corner, and moving clock-wise.

     // Bottom left corner
     [bottom_left_x + screw_dist_edge, bottom_left_y + screw_dist_edge, pos_z],

     // Middle of the left edge
     [bottom_left_x + screw_dist_edge, bottom_left_y + plate_width/2, pos_z],

     // Top left corner
     [bottom_left_x + screw_dist_edge, bottom_left_y + plate_width - screw_dist_edge, pos_z],

     // 2 holes on the top edge
     [bottom_left_x + plate_length/3, bottom_left_y + plate_width - screw_dist_edge, pos_z],
     [bottom_left_x + plate_length/3*2, bottom_left_y + plate_width - screw_dist_edge, pos_z],

     // Top right corner
     [bottom_left_x + plate_length - screw_dist_edge, bottom_left_y + plate_width - screw_dist_edge, pos_z],

     // Middle of the right edge
     [bottom_left_x + plate_length - screw_dist_edge, bottom_left_y + plate_width/2 - screw_dist_edge, pos_z],

     // Bottom right corner
     [bottom_left_x + plate_length - screw_dist_edge, bottom_left_y + screw_dist_edge, pos_z],

     // 2 holes on the bottom edge
     [bottom_left_x + plate_length/3*2, bottom_left_y + screw_dist_edge, pos_z],
     [bottom_left_x + plate_length/3, bottom_left_y + screw_dist_edge, pos_z],

     ];

module mounting_holes(){
     for (key = screw_holes) {
          translate([key[0], key[1], key[2]])
               cylinder(h=wall_height, r=screw_hole_radius, $fn=50, center=true);
     }
}

module usb_hole() {
     translate([bottom_left_x + (plate_length/2) - 10, bottom_left_y + plate_width - 10, (plate_thickness+wall_height)/2 - 10])
          cube([20,20,10]);
}

module bottom_box(h, w) {
     difference() {
          cube([h, w, plate_thickness + wall_height], center=true);
          translate([0,0,pos_z])
               cube([h - (wall_thickeness*2), w - (wall_thickeness*2), wall_height], center=true);
     }
}

module renzhi_bottom_plate() {
     difference() {
          bottom_box(plate_length, plate_width);
          mounting_holes();
          usb_hole();
     }
}

renzhi_bottom_plate();
