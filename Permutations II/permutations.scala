object Solution {

  def get_permutations(nums: List[Int]): Set[List[Int]] = nums match {
    case Nil => Set(Nil)
    case x :: xs => get_permutations(xs) flatMap { perm => 
      (0 to xs.length) map { num => (perm take num) ++ Set(x) ++ (perm drop num)
      }
    }
  }

  def permuteUnique(nums: Array[Int]): List[List[Int]] = nums.toList match {
    case Nil => Nil
    case xs => get_permutations(xs).toList
  }

  def main(args: Array[String]): Unit = {
    val nums = Array(1, 1, 2)
    val result = permuteUnique(nums)
    print(result)
  }
}
