
MIN_POINT = 0
STANDARD_MEMBERSHIP_POINT = 3000
PREMIUM_MEMBERSHIP_POINT = 10000

class GiftPoint:
    def __init__(self, value):
        if value < MIN_POINT:
            raise ValueError('ポイントが0以上ではありません')
        self.value = value
    
    def add(self, other):
        return GiftPoint(self.value + other.value)
    
    def isEnough(self, point):
        return point.value <= self.value

    def consume(self, point):
        if self.isEnough(point):
            raise ValueError('ポイントが不足しています')
        return GiftPoint(self.value - point.value)
    
    @staticmethod
    def standard_membership() {
        return GiftPoint(STANDARD_MEMBERSHIP_POINT)
    }

    @staticmethod
    def premium_membership() {
        return GiftPoint(PREMIUM_MEMBERSHIP_POINT)
    }