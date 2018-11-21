/* Comparator for a class in java
 */
//START
class bid implements Comparable<bid> {
    String person;
    BigInteger bd;

    public bid(String person, BigInteger bd) {
        this.person = person;
        this.bd = bd;
    }
    
    public int compareTo(bid other) {
        return this.bd.compareTo(other.bd);
    }
}
//END
