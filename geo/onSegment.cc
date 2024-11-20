/* On Segment
 * checks if a point lies on a segment
 */

 //START
def onSegment(s,e,p):
    return p.crossp(s,e) == 0 and (s-p).dot(e-p) <= 0
//END