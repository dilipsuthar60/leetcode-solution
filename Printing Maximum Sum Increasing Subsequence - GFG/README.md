# Printing Maximum Sum Increasing Subsequence
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">You are given an array <strong>A</strong>&nbsp;of length <strong>N</strong> .You have&nbsp;to find the maximum sum subsequence of a given sequence such that all elements of the subsequence are sorted in strictly increasing order. If there are more than one such subsequences,then print the sequence which ends closest to the starting index of the string.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 7
A = {1, 101, 2, 3, 100, 4, 5}
<strong>Output:</strong> {1, 2, 3, 100}
<strong>Explaination:</strong> This subsequence has the
highest sum of 106.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 5
A = {4, 2, 5, 3, 4}
<strong>Output:</strong> {4, 5}
<strong>Explaination:</strong> Here the subsequence {2, 3,
4} also  provides the sum 9. But that
ends at index 4. So, answer here is the
sequence {4, 5} which ends at 2nd index.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Your task is to complete the function <strong>maxSumSequence()</strong> which takes the array and <strong>N</strong> and returns the sequence.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N*N)<br>
<strong>Expected Auxiliary Space:</strong> O(N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 1000<br>
1 ≤ A[ i ] ≤ 10000</span></p>
 <p></p>
            </div>