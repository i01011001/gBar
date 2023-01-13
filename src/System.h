#pragma once
#include <string>
#include <vector>

namespace System
{
    // From 0-1, all cores
    double GetCPUUsage();
    // Tctl
    double GetCPUTemp();

    struct RAMInfo
    {
        double totalGiB;
        double freeGiB;
    };
    RAMInfo GetRAMInfo();

#ifdef HAS_NVIDIA
    struct GPUInfo
    {
        double utilisation;
        double coreTemp;
    };
    GPUInfo GetGPUInfo();

    struct VRAMInfo
    {
        double totalGiB;
        double usedGiB;
    };
    VRAMInfo GetVRAMInfo();
#endif

    struct DiskInfo 
    {
        double totalGiB;
        double usedGiB;
    };
    DiskInfo GetDiskInfo();

#ifdef HAS_BLUEZ
    struct BluetoothDevice
    {
        std::string name;
        // Known types: input-[keyboard,mouse]; audio-headset
        std::string type;
    };

    struct BluetoothInfo
    {
        std::string defaultController;
        std::vector<BluetoothDevice> devices;
    };
    BluetoothInfo GetBluetoothInfo();
#endif

    struct AudioInfo
    {
        double volume;
        bool muted;
    };
    AudioInfo GetAudioInfo();
    void SetVolume(double volume);

#ifdef HAS_HYPRLAND
    enum class WorkspaceStatus
    {
        Dead,
        Inactive,
        Visible,
        Current,
        Active
    };
    WorkspaceStatus GetWorkspaceStatus(uint32_t monitor, uint32_t workspace);
    void GotoWorkspace(uint32_t workspace);
#endif

    std::string GetTime();

    void Shutdown();
    void Reboot();
    void ExitWM();
    void Lock();
    void Suspend();

    void Init();
    void FreeResources();
}
