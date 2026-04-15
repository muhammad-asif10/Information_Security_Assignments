def shift_char(c, key):
    if 'a' <= c <= 'z':
        return chr((ord(c) - ord('a') + key) % 26 + ord('a'))
    elif 'A' <= c <= 'Z':
        return chr((ord(c) - ord('A') + key) % 26 + ord('A'))
    return c


def caesar_cipher(text, key, decrypt=False):
    if decrypt:
        key = -key

    return ''.join(shift_char(c, key) for c in text)


def main():
    print("=== Caesar Cipher Program ===")
    print("1. Encrypt")
    print("2. Decrypt")

    choice = input("Enter your choice (1 or 2): ").strip()
    message = input("Enter the message: ")
    key = int(input("Enter the key (shift number 1-25): "))

    key = key % 26

    if choice == '1':
        print("\nEncrypted Message:")
        print(caesar_cipher(message, key))
    elif choice == '2':
        print("\nDecrypted Message:")
        print(caesar_cipher(message, key, True))
    else:
        print("Invalid choice!")


if __name__ == "__main__":
    main()