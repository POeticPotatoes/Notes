## Tutorial 2 - Functions and Pointers

1. > Why the heck is the address not prefixed with `0x`  
   > Anything indeterminate is marked as :^), and segmentation faults are :^(
    1. 8, 0x7700, 100, 0x3478, :^(
    2. 100, 0x7700, 100, 0x3478, :^(
    3. 100, 0x7700, 0x7700, 0x3478, 100
    4. 10, 0x7700, 0x7700, 0x3478, 10
    5. *assuming addresses were given in hex,* 13432, 0x7700, 0x7700, 0x3478, 13432
    6. 13432, 0x7700, 0x3478, 0x3478, 0x3478

2.
    1. not returning anything (add return statement)
    2. not returning anything if n != 0 (add return statement)
    3. double assignment of variable a (remove the line)
    4. doesnt print the value of h (change & to *)
    5. void shouldn't return a value (remove the line)
    6. nested function definition isn't a thing (stop it)

3.
    ```
    h = 5, k = 15
    h = -100, k = -100
    h = 5, k = 15
    h = 5, k = 15
    h = 100, k = 100
    h = 5, k = 15
    h = 5, k = 15
    h = 200, k = 200
    h = 200, k = 200
    ```

4. Written in *cal_distance.c*
