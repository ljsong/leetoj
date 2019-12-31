object Solution {
   def stat(s: String): String = {
        var count = 1
        val ret = new StringBuilder()

        for (i <- s.indices) {
            if (i < s.length - 1 && s(i) == s(i + 1)) count += 1
            else {
                ret ++= count.toString + s(i).toString
                count = 1
            }
        }

        ret.toString
    }

    def countAndSay(n: Int): String = {
        if (n == 1) "1"
        else stat(countAndSay(n - 1))
    }
}
