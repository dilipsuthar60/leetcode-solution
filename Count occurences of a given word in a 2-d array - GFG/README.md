# Count occurences of a given word in a 2-d array
## Hard 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Find the number of occurrences of a given search word in&nbsp; a 2d-Array of characters where the word can go up, down, left, right and around 90 degree bends.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: 
</strong>R = 4, C = 5
mat = {{S,N,B,S,N},
       {B,A,K,E,A},
&nbsp;      {B,K,B,B,K},
       {S,E,B,S,E}}
target = SNAKES
<strong>Output:</strong>
3
<strong>Explanation</strong>: 
<span style="color:#800080">S</span> <span style="color:#800080">N</span> B <span style="color:#800080">S N</span>
B <span style="color:#800080">A K E</span> <span style="color:#800080">A</span>
B <span style="color:#800080">K</span> B B <span style="color:#4B0082">K</span>
<span style="color:#800080">S E</span> B <span style="color:#800080">S E</span>
Total occurrence of the word is 3
and denoted by color.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
R = 3, C = 3 
mat = {{c,a,t},
&nbsp;      {a,t,c},
&nbsp;      {c,t,a}}
target = cat
<strong>Output:</strong>
5
<strong>Explanation</strong>: Same explanation
as first example.</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Your task:</strong><br>
You don’t need to read input or print anything. Your task is to complete the function&nbsp;<strong>findOccurrence()</strong>&nbsp;which takes the mat&nbsp;contaning N*M 2-d array of character&nbsp;and target as input parameters and returns thethe number of occurrences of target.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity: </strong>O(R*C*2<sup>2*len</sup>), Where len is length of target String.<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(1)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ len&nbsp;≤ 15<br>
1 ≤ R, C&nbsp;≤ 50</span></p>
 <p></p>
            </div>