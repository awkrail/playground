import abc
import math

class Shape(metaclass=abc.ABCMeta):
    @abc.abstractmethod
    def area(self) -> float:
        return 0

class Recetangle(Shape):
    def __init__(self, width: float, height: float) -> None:
        self.width = width
        self.height = height
    
    def area(self):
        return self.width * self.height

class Circle(Shape):
    def __init__(self, radius: float) -> None:
        self.radius = radius
    
    def area(self):
        return math.pi * self.radius * self.radius

class Magic(metaclass=abc.ABCMeta):
    @abc.abstractmethod
    def name(self) -> str:
        return ''
    
    @abc.abstractmethod
    def costMagicPoint(self) -> int:
        return 0
    
    @abc.abstractmethod
    def attackPower(self) -> int:
        return 0
    
    @abc.abstractmethod
    def costTechnicalPoint(self) -> int:
        return 0

class Fire(Magic):
    def __init__(self, member) -> None:
        self.magic_point = 2
        self.name = "Fire"
        self.member = member

    @property
    def name(self) -> str:
        return self.name
    
    @property
    def costMagicPoint(self) -> int:
        return self.magic_point
    
    def attackPower(self) -> int:
        return 20 + (self.member * 0.5)

    def costTechnicalPoint(self) -> int:
        return 0

class HelFire(Magic):
    def __init__(self, member) -> None:
        self.magic_point = 16
        self.name = "HelFire"
        self.member = member

    @property
    def name(self) -> str:
        return self.name
    
    @property
    def costMagicPoint(self) -> int:
        return self.magic_point
    
    def attackPower(self) -> int:
        return 200 + (self.member.magicAttack * 0.5 + self.member.vitality * 2)

    def costTechnicalPoint(self) -> int:
        return 20 + (self.member.level * 0.4)

class purchaseHistory:
    def __init__(self, purchase_freq, total_amount, return_rate) -> None:
        self.purchase_freq = purchase_freq
        self.total_amount = total_amount
        self.return_rate = return_rate

class ExcellentCustomerRule(metaclass=abc.ABCMeta):
    @abc.abstractmethod
    def ok(self, history: purchaseHistory) -> bool:
        return True

class GoldCustomerPurchaseAmountRule(ExcellentCustomerRule):
    def ok(self, history: purchaseHistory) -> bool:
        return 100000 <= history.total_amount

class PurchaseFrequencyRule(ExcellentCustomerRule):
    def ok(self, history: purchaseHistory) -> bool:
        return 10 <= history.purchase_freq

class ReturnRateRule(ExcellentCustomerRule):
    def ok(self, history: purchaseHistory) -> bool:
        return history.return_rate <= 0.001

class ExcellentCustomerPolicy:
    def __init__(self) -> None:
        self.rules = set()
    
    def add(self, rule: ExcellentCustomerRule):
        self.rules.add(rule)
    
    def compolyWithAll(self, history: purchaseHistory) -> bool:
        for rule in self.rules:
            if not rule.ok(history):
                return False
        return True


rectanble: Recetangle = Recetangle(1.0, 2.0)
circle: Circle = Circle(3.0)

print(rectanble.area())
print(circle.area())