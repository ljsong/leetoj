object Solution {

  def get_combinations(candidates: List[Int], combs: List[Int], target: Int): Set[List[Int]] = candidates match {
    case Nil => {
      if (target == 0) Set(combs.sorted)
      else Set()
    }
    case x :: xs => {
      if (target < 0) Set()
      else if (target == 0) Set(combs.sorted)
      else get_combinations(xs, x :: combs, target - x) ++ get_combinations(xs, combs, target)
    }
  }

  def combinationSum2(candidates: Array[Int], target: Int): List[List[Int]] = candidates.toList match {
    case Nil => Nil
    case _ => get_combinations(candidates.toList, Nil, target).toList
  }

  def main(args: Array[String]): Unit = {
    val candidates = Array(2, 5, 2, 1, 2)
    val result = combinationSum2(candidates, 5)
    print(result)
  }
}

