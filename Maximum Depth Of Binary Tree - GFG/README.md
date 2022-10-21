# Maximum Depth Of Binary Tree
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a binary tree, find its <strong>maximum</strong>&nbsp;<strong>depth</strong>.<br>
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<div style="background: rgb(238, 238, 238); border: 1px solid rgb(204, 204, 204); padding: 5px 10px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor:#222426; --darkreader-inline-border-top:#3e4446; --darkreader-inline-border-right:#3e4446; --darkreader-inline-border-bottom:#3e4446; --darkreader-inline-border-left:#3e4446;"><span style="font-size:18px"><strong>Input:</strong><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 1<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp; \<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3&nbsp;&nbsp;&nbsp;&nbsp; 2<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; /<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><br>
<br>
<strong><span style="font-size:18px">Output:</span></strong><span style="font-size:18px"> 3<br>
<strong>Explanation:</strong><br>
Maximum depth is between nodes 1 and 4 since<br>
maximum depth is defined as&nbsp; the number of<br>
nodes along the shortest path from the root<br>
node down to the farthest leaf node.</span></div>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<div style="background: rgb(238, 238, 238); border: 1px solid rgb(204, 204, 204); padding: 5px 10px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor:#222426; --darkreader-inline-border-top:#3e4446; --darkreader-inline-border-right:#3e4446; --darkreader-inline-border-bottom:#3e4446; --darkreader-inline-border-left:#3e4446;"><span style="font-size:18px"><strong>Input:</strong><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 10<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp;&nbsp;&nbsp; \<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 20&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 30<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \&nbsp;&nbsp;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 40&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 60<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; /<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 2&nbsp;</span><br>
<br>
<strong><span style="font-size:18px">Output: </span></strong><span style="font-size:18px">4<br>
<br>
<strong>Explanation:</strong><br>
Minimum depth is between nodes 10,30,60 and 2.</span></div>

<p><br>
<span style="font-size:18px"><strong>Your Task: &nbsp;</strong><br>
You don't need to read input or print anything. Complete the function <strong>maxDepth()</strong> which takes the root node as an input parameter and returns the maximum depth.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity: </strong>O(N)<br>
<strong>Expected Auxiliary Space: </strong>O(height of the tree)</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10^5</span></p>
</div>