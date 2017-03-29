/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 
func convert(root *TreeNode, add int) (*TreeNode, int) {
    if (root == nil) {
        return nil, 0
    }
    var t TreeNode
    var lsum, rsum int
    t.Right, rsum = convert(root.Right, add)
    t.Left, lsum = convert(root.Left, rsum + root.Val + add)
    t.Val = root.Val + rsum + add
    return &t, lsum + rsum + root.Val
}

func convertBST(root *TreeNode) *TreeNode {
    t, _ := convert(root, 0)
    return t
}
