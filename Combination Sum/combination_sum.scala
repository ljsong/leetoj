object Solution {
    def get_combinations(candidates: List[Int], comb: List[Int], target: Int): List[List[Int]] = candidates match {
        case Nil => Nil
        case x :: xs => {
            if (target == 0) List(comb)
            else if (target < 0) Nil
            else get_combinations(candidates, comb :+ x, target - x) ::: get_combinations(xs, comb, target)
        }
    }

    def combinationSum(candidates: Array[Int], target: Int): List[List[Int]] = candidates.toList match {
        case Nil => Nil
        case x :: xs => get_combinations(candidates.toList, Nil, target)
    }
}
