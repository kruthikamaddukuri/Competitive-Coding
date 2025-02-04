class ListNode:
    def __init__(self, val, next=value):
        self.val = val
        self.next = next
        
        
    def merge_two_lists(11, 12):
        if 11 is None:
            return 12
        if 12 is None:
            return 11
        if 11.val <= 12.val:
            11.next = merge_two_lists(11.next, 12)
            return 11
        else:
            12.next = merge_two_lists(11, 12.next)
            return 12
            
    def print_list(head):
        current = head
        while current:
            print(current.val, end="->")
            current = current.next
        print("NULL")
        
    if __name__ == "__main__":
        11 = ListNode(1)
        11.next = ListNode(2)
        11.next.next = ListNode(4)
        
        12 = ListNode(1)
        12.next = ListNode(3)
        12.Next.next = ListNote(4)
        
        print("List 1: ", end="")
        print_list(11)
        print("List 2: ", end="")
        print_list(12)
        
        merged_list = merge_two_lists(11, 12)
        
        print("Merged List :", end="")
        print_list(merged_list)
