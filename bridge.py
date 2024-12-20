from azure.iot.device import ProvisioningDeviceClient, IoTHubDeviceClient
import time

# DPS settings
ID_SCOPE = "<ID-scope>"  # Replace with your ID Scope
DEVICE_ID = "<device-ID>"  # Replace with your Device ID
DEVICE_KEY = "<device-key>"  # Replace with your Device Key
PROVISIONING_HOST = "global.azure-devices-provisioning.net"  # DPS global endpoint

# Function to initialize the IoT Hub client
def create_client():
    # Create a provisioning client
    provisioning_client = ProvisioningDeviceClient.create_from_symmetric_key(
        provisioning_host=PROVISIONING_HOST,
        registration_id=DEVICE_ID,
        id_scope=ID_SCOPE,
        symmetric_key=DEVICE_KEY
    )

    print("Registering device...")
    registration_result = provisioning_client.register()

    if registration_result.status == "assigned":
        print("Device successfully registered!")
        print(f"Assigned IoT Hub HostName: {registration_result.registration_state.assigned_hub}")

        # Use the assigned IoT Hub HostName to create an IoT Hub device client
        client = IoTHubDeviceClient.create_from_symmetric_key(
            symmetric_key=DEVICE_KEY,
            hostname=registration_result.registration_state.assigned_hub,
            device_id=DEVICE_ID
        )
        client.connect()
        print("IoT Hub client connected successfully!")
        return client
    else:
        raise Exception(f"Device registration failed: {registration_result.status}")

# Main function
def main():
    client = None
    try:
        # Create and connect the client
        client = create_client()
        print("Client is now running. Sending messages...")

        while True:
            # Simulate sending data
            message = '{"temperature": 22.5, "humidity": 60}'  # Replace with actual sensor data
            print(f"Sending message: {message}")
            client.send_message(message)
            print("Message sent successfully!")

            # Wait before sending the next message
            time.sleep(10)  # Send every 10 seconds (adjust as needed)
    except KeyboardInterrupt:
        print("Exiting...")
    except Exception as e:
        print(f"An error occurred: {e}")
    finally:
        if client:
            print("Shutting down client...")
            client.shutdown()

# Run the script
if __name__ == "__main__":
    main()