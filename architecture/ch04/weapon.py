class AttackPower:
    def __init__(self, value: int):
        if value < 0:
            raise ValueError('value should be larger than 0')
        self.value: int = value
    
    def reinForce(self, increment):
        return AttackPower(self.value + increment.value)
    
    def disable(self):
        return AttackPower(0)


class Weapon:
    def __init__(self, attack_power: AttackPower):
        self.attack_power = attack_power
    
    def reinForce(self, increment: AttackPower):
        reinforced = self.attack_power.reinForce(increment)
        return Weapon(reinforced)

attack_power_1 = AttackPower(20)
weapon_A = Weapon(attack_power_1)
attack_power_2 = AttackPower(30)
weapon_B = weapon_A.reinForce(attack_power_2)
print(weapon_A.attack_power.value)
print(weapon_B.attack_power.value)