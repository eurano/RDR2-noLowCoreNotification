#include "script.h"

constexpr float DEAD_EYE_THRESHOLD = 0.83f;

inline bool isToastInBlockingRange(int state) {
    return (state >= 0 && state <= 5);
}

void update() {
    Player player = PLAYER::PLAYER_ID();

    int toastId = UIUNK::_0xC17F69E1418CD11F(1);
    if (toastId == 0) return;

    int toastState = UIUNK::_0x59FA676177DBE4C9(toastId);
    if (!isToastInBlockingRange(toastState)) return;

    float deadeyeCoreLvl = PLAYER::_0x3A6AE4EEE30370FE(player, false);
    if (deadeyeCoreLvl >= DEAD_EYE_THRESHOLD) return;

    UIUNK::_0x2F901291EF177B02(toastId, true);
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

