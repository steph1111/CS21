# Lab hours: Week 3
**Total Hours:** 4.5

## Timed and optimized code for displaying h264 encoded camera frames (2 hours)
In the robotics club I am working on displaying a h264 encoded camera stream to a PyQt window. 
This week I continued to apply what Ive learned analyzing algorithms to find the best way
of displaying the video which consumes the least resources and time. I currently have found a way
which displays the video frame by frame to the window at a relatively fast speed, however
there is still an extra traverse over the pixel array which I am hoping to optimize away.

## Optimal way to read chars and words from a file in Python (2.5 hours)
I've noticed I have to pay even more attention to my algorithm design when programming in Python. Something which is
un-optimized may be unnoticeable in a compiled language like C, but the equivalent code in Python 
is often visibly slow. I spent some programming the best way (in both space and time) I could come up with to read words
and individual chars from a file in Python. Reading chunks of bytes at a time was useful in saving space and even sped up the time.
For reading in just chars this was a easy solution, but to read in white space delimited tokens (or words) this method alone proved to be
inadequate as the tokens may be split in the middle. I developed a generator which yields words read from a file in "byte chunks" accounting
for the fact the word may be split in half when read in.