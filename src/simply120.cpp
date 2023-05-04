#include "GlobalNamespace/VRRenderingParamsSetup.hpp"
#include "GlobalNamespace/OVRPlugin.hpp"
#include "UnityEngine/Mathf.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"

MAKE_HOOK_MATCH(
    VRRenderingParamsSetup_OnEnable,
    &GlobalNamespace::VRRenderingParamsSetup::OnEnable,
    void,
    GlobalNamespace::VRRenderingParamsSetup* self
) {
    using namespace GlobalNamespace;
    using namespace UnityEngine;
 
    //Run original first
    VRRenderingParamsSetup_OnEnable(self);

    //Maximize refresh rate
    float refreshRate = Mathf::Max(OVRPlugin::get_systemDisplayFrequenciesAvailable());
    OVRPlugin::set_systemDisplayFrequency(refreshRate);
}

void simply120_hook(Logger &logger) {
    INSTALL_HOOK(logger, VRRenderingParamsSetup_OnEnable);
}