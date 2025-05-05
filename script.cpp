#include "script.h"  
#include "natives.h"  
#include "types.h"  
#include "nativeCaller.h"  
#include "enums.h"  
#include <string> 

// Simple range check returns directly
inline bool isMessShownNow(int toastState) {
    return toastState >= 0 && toastState <= 5;
}

void update() {
    constexpr float DEAD_EYE_THRESHOLD = 0.83f;
    int toastId = 0;
    Player player = PLAYER::PLAYER_ID();
    toastId = UIUNK::_0xC17F69E1418CD11F(1);  // Get toast ID

    if (toastId != 0) {
        int toastState = UIUNK::_0x59FA676177DBE4C9(toastId);  // Get message type
        float deadeyeCoreLvl = PLAYER::_0x3A6AE4EEE30370FE(player, false);  // Deadeye level

        if (deadeyeCoreLvl < DEAD_EYE_THRESHOLD && isMessShownNow(toastState)) {
            UIUNK::_0x2F901291EF177B02(toastId, true);  // Actively block toast
        }
    }

    WAIT(0);
}

void main() {
    while (true) {
        update();
        WAIT(0);
    }
}

void ScriptMain() {
    srand(GetTickCount());
    main();
}
