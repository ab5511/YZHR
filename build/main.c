#include <engine/Engine.h>
#include <stdio.h>
#include <inttypes.h>

con _c_* log_color[] = {
    "\033[0;32m",
    "\033[0;36m",
    "\033[0;33m",
    "\033[0;31m",
    "\033[0;35m",
    "\033[0m"
};
con _c_* log_level[] = {
    "info",
    "debug",
    "warning",
    "error",
    "critical"
};
_n_ log_callback_func(Elog1_context_T context){
    context.level = context.level %5;
    if(!context.who){
        context.who = "null";
    }
    if(!context.message){
        context.message = "null";
    }
    printf("%slevel: %s | who: %s | handle: %p | message:\n-->>%s\033[0m\n",
        log_color[context.level],
        log_level[context.level],
        context.who, context.hand,
        context.message
    );
}

int main() {
    Eset_log1(&log_callback_func);
    if(!Eis_engine_dll_loaded()){
        printf("Engine DLL is not loaded.\n");
        ret -1;
    }
    _u32 _engine_version = dll_set.get_version();
    printf("dll version: %" PRIu32 "\n", _engine_version);

    ret 0;
}