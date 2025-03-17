#!/usr/bin/python3
import smbus2
import sys
import argparse

I2C_DEV = 10
I2C_ADDR = 0x3b

# Define register addresses
Manufacturer_Name = 0x0000
Model_Name = 0x0004
Device_Version = 0x0010
Product_Info = 0x000C
Time_stamp = 0x0020
Error_code = 0x0024

# More registers would go here...

def print_usage():
    print("Usage:  mv_mipi_i2c.py [-r/w]  [function name] [param1] [param2] [param3] [param4] -b bus -d addr")
    print("options:")
    print("    -r                       read ")
    print("    -w                       write")
    print("    [function name]          function name")
    print("    [param1]                 param1 of each function")
    print("    [param2]                 param2 of each function")
    print("    [param3]                 param3 of each function")
    print("    [param4]                 param4 of each function")
    print("    -b [i2c bus num]         i2c bus number")
    print("    -d [i2c addr]            i2c addr if not default 0x3b")
    print("Please open this script and read the COMMENT on top for support functions and samples")

def read_i2c(bus, addr, reg):
    with smbus2.SMBus(bus) as bus:
        # Write register address (2 bytes)
        bus.write_i2c_block_data(addr, reg >> 8, [reg & 0xFF])
        # Read 4 bytes from the register
        read = bus.read_i2c_block_data(addr, reg, 4)
        value = int.from_bytes(read, byteorder='big')
        return value

def write_i2c(bus, addr, reg, data):
    with smbus2.SMBus(bus) as bus:
        # Write register address (2 bytes) and data (4 bytes)
        data_bytes = data.to_bytes(4, byteorder='big')
        bus.write_i2c_block_data(addr, reg >> 8, [reg & 0xFF] + list(data_bytes))

def read_manufacturer(bus, addr):
    manufacturer = read_i2c(bus, addr, Manufacturer_Name)
    if manufacturer == 1447385413:
        print("Manufacturer is VEYE")
    else:
        print(f"Manufacturer {manufacturer:08x} not recognized")

def read_model(bus, addr):
    model = read_i2c(bus, addr, Model_Name)
    models = {
        662: "MV-MIPI-IMX296M",
        376: "MV-MIPI-IMX178M",
        304: "MV-MIPI-SC130M",
        613: "MV-MIPI-IMX265M",
        612: "MV-MIPI-IMX264M",
        647: "MV-MIPI-IMX287M",
        33074: "RAW-MIPI-SC132M",
        33332: "RAW-MIPI-AR0234M",
        33890: "RAW-MIPI-IMX462M",
        34101: "RAW-MIPI-SC535M"
    }
    print(f"Model is {models.get(model, f'not recognized {model:08x}')}")


def read_version(bus, addr):
    version = read_i2c(bus, addr, Device_Version)
    print(f"Version is C {(version >> 24) & 0xFF}.{(version >> 16) & 0xFF} and L {(version >> 8) & 0xFF}.{version & 0xFF}")

def read_serialno(bus, addr):
    serialno = read_i2c(bus, addr, Product_Info)
    print(f"Serial number is 0x{serialno:x}")

def read_timestamp(bus, addr):
    timestamp = read_i2c(bus, addr, Time_stamp)
    print(f"Timestamp is {timestamp}")

def read_errcode(bus, addr):
    errcode = read_i2c(bus, addr, Error_code)
    print(f"Error code is {errcode}")

# Define more read/write functions here...

def main():
    parser = argparse.ArgumentParser(description='I2C read/write script')
    parser.add_argument('-r', '--read', action='store_true', help='read mode')
    parser.add_argument('-w', '--write', action='store_true', help='write mode')
    parser.add_argument('function', type=str, help='function name')
    parser.add_argument('params', type=int, nargs='*', help='parameters for the function')
    parser.add_argument('-b', '--bus', type=int, default=I2C_DEV, help='I2C bus number')
    parser.add_argument('-d', '--addr', type=int, default=I2C_ADDR, help='I2C address')

    args = parser.parse_args()

    if args.read and args.function:
        if args.function == 'manufacturer':
            read_manufacturer(args.bus, args.addr)
        elif args.function == 'model':
            read_model(args.bus, args.addr)
        elif args.function == 'version':
            read_version(args.bus, args.addr)
        elif args.function == 'serialno':
            read_serialno(args.bus, args.addr)
        elif args.function == 'timestamp':
            read_timestamp(args.bus, args.addr)
        elif args.function == 'errcode':
            read_errcode(args.bus, args.addr)
        else:
            print(f"Function {args.function} not recognized for read operation")

    elif args.write and args.function and args.params:
        # Implement write functions here
        pass

    else:
        print_usage()

if __name__ == "__main__":
    main()
