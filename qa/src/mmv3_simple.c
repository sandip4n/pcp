/* C language writer - using the application-level API, MMV v2 */
/* Build via: cc -g -Wall -lpcp_mmv -o mmv_simple mmv_simple.c */

#include <pcp/pmapi.h>
#include <pcp/mmv_stats.h>

static mmv_metric2_t metrics[] = {
    {   .name = "simple2.counter",
        .item = 1,
        .type = MMV_TYPE_U32,
        .semantics = MMV_SEM_COUNTER,   
        .dimension = MMV_UNITS(0,0,1,0,0,PM_COUNT_ONE),
        .shorttext = NULL,
        .helptext = NULL,
    },
    {   .name =
        "simple2.metric.with.a.much.longer.metric.name.forcing.version2.format",
        .item = 1,
        .type = MMV_TYPE_U64,
        .semantics = MMV_SEM_COUNTER,
        .dimension = MMV_UNITS(0,0,1,0,0,PM_COUNT_ONE),
        .shorttext = NULL,
        .helptext = NULL,
    },
};

int 
main(int argc, char **argv)
{
    pmAtomValue *value;
    char *file = (argc > 1) ? argv[1] : "simple3";
    mmv_registry_t *addr = mmv_stats_registry(file, 321, 0);

    if (!addr) {
        fprintf(stderr, "mmv_metric_register: %s - %s\n", file, strerror(errno));
        return 1;
    }
    fprintf(stderr, "File: %s \n", file);
    fprintf(stderr, "File: %s \n", addr->file);
    fprintf(stderr, "File: %d \n", addr->cluster);
    fprintf(stderr, "File: %d \n", addr->flags);
    fprintf(stderr, "File: %s \n", metrics[0].name);
    //char * aux = metrics[0].name;
    //fprintf(stderr, "File: %d \n", sizeof(metrics[0].name));
    //strncpy(aux, metrics[0].name, sizeof(metrics[0].name));
    //fprintf(stderr, "File: %s \n", aux);
    

    // Add metric
    mmv_stats_add_metric(addr,metrics[0].name,metrics[0].item,metrics[0].type,
                         metrics[0].semantics,metrics[0].dimension,0,metrics[0].shorttext,
                         metrics[0].helptext);
    //value = mmv_lookup_value_desc(addr, "simple.counter", NULL);
    //mmv_inc_value(addr, value, 42);

    //mmv_stats_stop(file, addr);
    return 0;
}
