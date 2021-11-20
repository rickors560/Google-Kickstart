## Problem

    You have recently started to study how to paint, and in one of the first classes you learned about the three primary colors: Red, Yellow, and Blue. If you combine these colors, you can produce many more colors. For now, the combinations that you have studied are the following:

    Red + Yellow = Orange
    Red + Blue = Purple
    Yellow + Blue = Green
    Red + Yellow + Blue = Gray
    You still do not understand shades of colors, therefore the proportion and order of each color in the combination does not matter. For example, combining Red and Yellow produces the same result as combining Yellow and Red, as well as the same result as combining Red, Yellow, and Red again.

    To practice your skills, you want to paint a 1-dimensional painting P of length N. Your painting consists of N squares. From left to right, Pi represents the color of the i-th square. Initially all squares are Uncolored, that is, Pi = Uncolored for every 1≤i≤N.

    In a single stroke, you can choose one of the three primary colors and apply it to a sequence of consecutive squares. In other words, you can choose a color c and two integers l and r, such that 1≤l≤r≤N, and apply color c to all squares Pj such that l≤j≤r. If the square being painted is currently Uncolored, then its color will become c. Otherwise, the color will be a combination of all the colors applied on this square so far and the new color c, as described in the list above.

    In order to save time, you want to use as few strokes as possible. Given the description of the painting that you want to paint, figure out what is the minimum number of strokes required to paint it.

### Input

    The first line of the input gives the number of test cases, T. T test cases follow.

    Each test case starts with a line containing an integer N, representing the length of the painting. Then on the next line, there will be a string P of length N, representing the painting. The i-th character represents the color of square Pi, according to the following list:

    U = Uncolored
    R = Red
    Y = Yellow
    B = Blue
    O = Orange
    P = Purple
    G = Green
    A = Gray
    Output
    For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum number of strokes required to paint the painting.

### Limits

    Memory limit: 1 GB.
    1≤T≤100.
    1≤N≤105.

### Test Set 1

    Time limit: 20 seconds.
    Pi will be one of {Y, B, G}.

### Test Set 2

    Time limit: 40 seconds.
    Pi will be one of {U, R, Y, B, O, P, G, A}.

### Sample

    Note: there are additional samples that are not run on submissions down below.

***Sample Input***

    2
    9
    YYYBBBYYY
    6
    YYGGBB

***Sample Output***

    Case #1: 3
    Case #2: 2

In Sample Case #1, the solution is to make 3 strokes: the first one using color Yellow from square 1 through 3, the second one using color Blue from square 4 through 6, and the third one using color Yellow from square 7 through 9. Notice that this particular painting required only primary colors.

In Sample Case #2, the solution is to make 2 strokes: the first one using color Yellow from square 1 through 4, and the second one using color Blue from square 3 through 6. Notice that squares 3 and 4 will be painted with both colors Yellow and Blue, which will result on it being Green.


### Additional Sample - Test Set 2

    The following additional sample fits the limits of Test Set 2. It will not be run against your submitted solutions.

***Sample Input***

    1
    5
    ROAOR

***Sample Output***

    Case #1: 3

In Sample Case #3, the solution is to make 3 strokes: the first one using color Red from square 1 through 5, the second one using color Yellow from square 2 through 4, and the third one using color Blue on square 3. Notice that square 3 is painted with all three primary colors, which will result in it being Gray.

## Problem Link
    https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008d9a88#problem