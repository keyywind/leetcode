class NumArray {
public:
    static constexpr int MAX_SIZE = 10000;
    static int array[MAX_SIZE];
    NumArray(vector<int>& nums) {
        array[0] = nums[0];
        for (int i = 1, size = nums.size(); i < size; ++i)
            array[i] = array[i - 1] + nums[i];
    }

    int sumRange(int left, int right) {
        return ((left) ? (array[right] - array[left - 1]) : (array[right]));
    }
};
int NumArray::array[NumArray::MAX_SIZE];
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
