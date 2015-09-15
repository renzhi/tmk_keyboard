/**
 * Copyright (C) 2015, xp@renzhi.ca, all rights reserverd.
 */

/**
 * Note: Dimension units are all in mm, except angle, which is in degrees.
 */

// Thickness of entire plate
plate_thickness = 3;
wall_height = 12;
plate_length = 310;
plate_width = 170;

bottom_left_x = -(plate_length / 2);
bottom_left_y = -(plate_width / 2);

//Radius of mounting screw holes
screw_hole_radius = 2;
// Distance of a screw from the edge
screw_dist_edge = 5;

// Radius of the rounded corner used with minkowski function.
round_radius = 5;

screw_holes = [
     // Starting at the bottom left corner, and moving clock-wise.

     // Bottom left corner
     [bottom_left_x + screw_dist_edge, bottom_left_y + screw_dist_edge, 0],

     // Middle of the left edge
     [bottom_left_x + screw_dist_edge, bottom_left_y + plate_width/2, 0],

     // Top left corner
     [bottom_left_x + screw_dist_edge, bottom_left_y + plate_width - screw_dist_edge, 0],

     // 2 holes on the top edge
     [bottom_left_x + plate_length/3, bottom_left_y + plate_width - screw_dist_edge, 0],
     [bottom_left_x + plate_length/3*2, bottom_left_y + plate_width - screw_dist_edge, 0],

     // Top right corner
     [bottom_left_x + plate_length - screw_dist_edge, bottom_left_y + plate_width - screw_dist_edge, 0],

     // Middle of the right edge
     [bottom_left_x + plate_length - screw_dist_edge, bottom_left_y + plate_width/2, 0],

     // Bottom right corner
     [bottom_left_x + plate_length - screw_dist_edge, bottom_left_y + screw_dist_edge, 0],

     // 2 holes on the bottom edge
     [bottom_left_x + plate_length/3*2, bottom_left_y + screw_dist_edge, 0],
     [bottom_left_x + plate_length/3, bottom_left_y + screw_dist_edge, 0],

     ];

module mounting_holes(){
     for (key = screw_holes) {
          translate([key[0], key[1], key[2]])
               cylinder(h=wall_height, r=screw_hole_radius, $fn=50, center=true);
     }
}

module bottom_plate() {
     $fn = 150;
     minkowski() {
          cube([plate_length, plate_width, plate_thickness], center=true);
          cylinder(r=round_radius);
     }
}

module renzhi_bottom_plate() {
     difference() {
          bottom_plate();
          mounting_holes();
     }
}

renzhi_bottom_plate();
