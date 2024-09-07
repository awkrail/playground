class MagicPoint:
    def __init__(self, current_amount, original_max_amount, max_increments):
        self.current_amount = current_amount
        self.original_max_amount = original_max_amount
        self.max_increments = max_increments
    
    @property
    def current(self):
        return self.current_amount

    def max(self):
        amount = self.original_max_amount
        for each in self.max_increments:
            amount += each
        return amount
    
    def recover(self, recovery_amount):
        self.current_amount = min(self.current_amount + recovery_amount, self.max())