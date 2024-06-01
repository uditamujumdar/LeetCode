/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let arr2=arr;
    for(let i=0;i<arr2.length;i++){
        arr2[i]=fn(arr[i],i);
    }
    return arr2;
};