/**
 * Copyright (C) 2015, xp@renzhi.ca, all rights reserverd.
 */

/**
 * Note: Dimension units are all in mm, except angle, which is in degrees.
 */

// Thickness of entire plate
plate_thickness = 3;
// Dimensions of the plate
plate_length = 310;
plate_width = 170;

bottom_left_x = -(plate_length / 2);
bottom_left_y = -(plate_width / 2);

// Each key occupies an area of 19.5 x 19.5, and the key hole will be in the middle of this area.
key_size = 19.5;
// Switch hole size, based on the Cherry MX data sheet
hole_size = 14;
// Distance from the key size edge to the edge of the key whole
key_hole_edge = 2.75;

// Starting position of the left most key on left hand side
startx = bottom_left_x + 15;
starty = bottom_left_y + 100;

// Matrix key angle on the left hand side is 62 degrees, clock-wise.
matrix_angle = 28;

//Radius of mounting screw holes
screw_hole_radius = 2;
// Distance of a screw from the edge
screw_dist_edge = 5;

// Radius of the rounded corner used with minkowski function.
round_radius = 5;

/*
 * Put srew holes around the edges:
 * 4 screw holes, each at the 4 corners.
 * 2 on the bottom edge, equally dividing the bottom edge into 3 segments.
 * 2 on the top edge, equally dividing the top edge into 3 segments.
 * 1 on the left edge, dividing the left edge into 2 segments.
 * 1 on the right edge, dividing the right edge into 2 segments.
 */
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

l_matrix = [
     // 1st column
     [key_hole_edge, key_hole_edge, 0],
     [key_hole_edge, key_hole_edge + key_size, 0],
     [key_hole_edge, key_hole_edge + (key_size*2), 0],
     [key_hole_edge, key_hole_edge + (key_size*3), 0],

     // 2nd column
     [key_hole_edge + key_size, key_hole_edge, 0],
     [key_hole_edge + key_size, key_hole_edge + key_size, 0],
     [key_hole_edge + key_size, key_hole_edge + (key_size*2), 0],
     [key_hole_edge + key_size, key_hole_edge + (key_size*3), 0],

     // 3rd column
     [key_hole_edge + (key_size*2), key_hole_edge + 16, 0],
     [key_hole_edge + (key_size*2), key_hole_edge + 16 + key_size, 0],
     [key_hole_edge + (key_size*2), key_hole_edge + 16 + (key_size*2), 0],
     [key_hole_edge + (key_size*2), key_hole_edge + 16 + (key_size*3), 0],

     // 4th column
     [key_hole_edge + (key_size*3), key_hole_edge + 16, 0],
     [key_hole_edge + (key_size*3), key_hole_edge + 16 + key_size, 0],
     [key_hole_edge + (key_size*3), key_hole_edge + 16 + (key_size*2), 0],
     [key_hole_edge + (key_size*3), key_hole_edge + 16 + (key_size*3), 0],

     // 5th column
     [key_hole_edge + (key_size*4), key_hole_edge + 7, 0],
     [key_hole_edge + (key_size*4), key_hole_edge + 7 + key_size, 0],
     [key_hole_edge + (key_size*4), key_hole_edge + 7 + (key_size*2), 0],
     [key_hole_edge + (key_size*4), key_hole_edge + 7 + (key_size*3), 0],

     // 6th column
     [key_hole_edge + (key_size*5), key_hole_edge + 16, 0],
     [key_hole_edge + (key_size*5), key_hole_edge + 16 + key_size, 0],
     [key_hole_edge + (key_size*5), key_hole_edge + 16 + (key_size*2), 0],
     [key_hole_edge + (key_size*5), key_hole_edge + 16 + (key_size*3), 0]

     ];

l_thumb_cluster = [
     // Note: because of rotation, we need to add extra padding for x-coordinates,
     //       otherwise, keycaps might not fit.
     [[key_hole_edge + (key_size*3.5) - 2, key_hole_edge + 7 - key_size - 2, 0],[0,0,-5]],
     [[key_hole_edge + (key_size*4.5) + 1, key_hole_edge + 7 - key_size - 5, 0],[0,0,-9]],
     [[key_hole_edge + (key_size*5.5) + 4, key_hole_edge + 7 - key_size - 9, 0],[0,0,-14]],
     [[key_hole_edge + (key_size*6.5) + 7, key_hole_edge + 7 - key_size - 15, 0],[0,0,-20]],

     // Fn key, right below the second key from the left, aligned to exactly the same angle.
     //[[key_hole_edge + (key_size*4.5) - 10, key_hole_edge + 7 - key_size - 55, 0],[0,0,-10]]
     [[key_hole_edge + (key_size*5.4) - 10, key_hole_edge + 7 - key_size - 30, 0],[0,0,-10]]
     ];

module plate(){
     $fn = 150;
     minkowski() {
          cube([plate_length, plate_width, plate_thickness], center=true);
          cylinder(r=round_radius);
     }
}

module left_matrix() {
     translate([startx, starty, 0])
     rotate([0, 0, -matrix_angle]) {
          for (key = l_matrix) {
               translate([key[0], key[1], key[2]])
                    cube(hole_size, hole_size, plate_thickness, center=true);
          }

          for (key = l_thumb_cluster) {
               translate([key[0][0], key[0][1], key[0][2]])
                    rotate([key[1][0], key[1][1], key[1][2]])
                    cube(hole_size, hole_size, plate_thickness, center=true);
          }

     }
}

module mounting_holes(){
     for (key = screw_holes) {
          translate([key[0], key[1], key[2]])
               cylinder(h=plate_thickness + 10, r=screw_hole_radius, $fn=50, center=true);
     }
}

module key_matrix() {
     left_matrix();
     mirror([1,0,0])
          left_matrix();
  }

module renzhi_plate() {
     difference() {
          plate();
          mounting_holes();
          key_matrix();
     }
}

projection(cut=false)
        renzhi_plate();
