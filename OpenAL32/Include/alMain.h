#ifndef AL_MAIN_H
#define AL_MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#ifdef HAVE_FENV_H
#include <fenv.h>
#endif

#ifdef HAVE_FPU_CONTROL_H
#include <fpu_control.h>
#endif

#include "AL/al.h"
#include "AL/alc.h"
#include "AL/alext.h"

#ifndef ALC_SOFT_device_loopback
#define ALC_SOFT_device_loopback 1
#define ALC_FORMAT_CHANNELS_SOFT                 0x1990
#define ALC_FORMAT_TYPE_SOFT                     0x1991

/* Sample types */
#define ALC_BYTE_SOFT                            0x1400
#define ALC_UNSIGNED_BYTE_SOFT                   0x1401
#define ALC_SHORT_SOFT                           0x1402
#define ALC_UNSIGNED_SHORT_SOFT                  0x1403
#define ALC_INT_SOFT                             0x1404
#define ALC_UNSIGNED_INT_SOFT                    0x1405
#define ALC_FLOAT_SOFT                           0x1406

/* Channel configurations */
#define ALC_MONO_SOFT                            0x1500
#define ALC_STEREO_SOFT                          0x1501
#define ALC_QUAD_SOFT                            0x1503
#define ALC_5POINT1_SOFT                         0x1504 /* (WFX order) */
#define ALC_6POINT1_SOFT                         0x1505 /* (WFX order) */
#define ALC_7POINT1_SOFT                         0x1506 /* (WFX order) */

typedef ALCdevice* (ALC_APIENTRY*LPALCLOOPBACKOPENDEVICESOFT)(void);
typedef ALCboolean (ALC_APIENTRY*LPALCISRENDERFORMATSUPPORTEDSOFT)(ALCdevice *device, ALCsizei freq, ALCenum channels, ALCenum type);
typedef void (ALC_APIENTRY*LPALCRENDERSAMPLESSOFT)(ALCdevice *device, ALCvoid *buffer, ALCsizei samples);
#ifdef AL_ALEXT_PROTOTYPES
ALC_API ALCdevice* ALC_APIENTRY alcLoopbackOpenDeviceSOFT(void);
ALC_API ALCboolean ALC_APIENTRY alcIsRenderFormatSupportedSOFT(ALCdevice *device, ALCsizei freq, ALCenum channels, ALCenum type);
ALC_API void ALC_APIENTRY alcRenderSamplesSOFT(ALCdevice *device, ALCvoid *buffer, ALCsizei samples);
#endif
#endif

#ifndef AL_SOFT_buffer_samples
#define AL_SOFT_buffer_samples 1
/* Sample types */
#define AL_BYTE                                  0x1400
#define AL_UNSIGNED_BYTE                         0x1401
#define AL_SHORT                                 0x1402
#define AL_UNSIGNED_SHORT                        0x1403
#define AL_INT                                   0x1404
#define AL_UNSIGNED_INT                          0x1405
#define AL_FLOAT                                 0x1406
#define AL_DOUBLE                                0x1407
#define AL_BYTE3                                 0x1408
#define AL_UNSIGNED_BYTE3                        0x1409
#define AL_MULAW                                 0x1410
#define AL_ALAW                                  0x1411
#define AL_IMA4                                  0x1412

/* Channel configurations */
#define AL_MONO                                  0x1500
#define AL_STEREO                                0x1501
#define AL_REAR                                  0x1502
#define AL_QUAD                                  0x1503
#define AL_5POINT1                               0x1504 /* (WFX order) */
#define AL_6POINT1                               0x1505 /* (WFX order) */
#define AL_7POINT1                               0x1506 /* (WFX order) */

/* Storage formats */
#define AL_MONO8                                 0x1100
#define AL_MONO16                                0x1101
#define AL_MONO32F                               0x10010
#define AL_STEREO8                               0x1102
#define AL_STEREO16                              0x1103
#define AL_STEREO32F                             0x10011
#define AL_QUAD8                                 0x1204
#define AL_QUAD16                                0x1205
#define AL_QUAD32F                               0x1206
#define AL_REAR8                                 0x1207
#define AL_REAR16                                0x1208
#define AL_REAR32F                               0x1209
#define AL_5POINT1_8                             0x120A
#define AL_5POINT1_16                            0x120B
#define AL_5POINT1_32F                           0x120C
#define AL_6POINT1_8                             0x120D
#define AL_6POINT1_16                            0x120E
#define AL_6POINT1_32F                           0x120F
#define AL_7POINT1_8                             0x1210
#define AL_7POINT1_16                            0x1211
#define AL_7POINT1_32F                           0x1212

/* Buffer attributes */
#define AL_INTERNAL_FORMAT                       0x2008
#define AL_BYTE_LENGTH                           0x2009
#define AL_SAMPLE_LENGTH                         0x200A
#define AL_SEC_LENGTH                            0x200B

typedef void (AL_APIENTRY*LPALBUFFERSAMPLESSOFT)(ALuint,ALuint,ALenum,ALsizei,ALenum,ALenum,const ALvoid*);
typedef void (AL_APIENTRY*LPALBUFFERSUBSAMPLESSOFT)(ALuint,ALsizei,ALsizei,ALenum,ALenum,const ALvoid*);
typedef void (AL_APIENTRY*LPALGETBUFFERSAMPLESSOFT)(ALuint,ALsizei,ALsizei,ALenum,ALenum,ALvoid*);
typedef ALboolean (AL_APIENTRY*LPALISBUFFERFORMATSUPPORTEDSOFT)(ALenum);
#ifdef AL_ALEXT_PROTOTYPES
AL_API void AL_APIENTRY alBufferSamplesSOFT(ALuint buffer,
    ALuint samplerate, ALenum internalformat, ALsizei samples,
    ALenum channels, ALenum type, const ALvoid *data);
AL_API void AL_APIENTRY alBufferSubSamplesSOFT(ALuint buffer,
    ALsizei offset, ALsizei samples,
    ALenum channels, ALenum type, const ALvoid *data);
AL_API void AL_APIENTRY alGetBufferSamplesSOFT(ALuint buffer,
    ALsizei offset, ALsizei samples,
    ALenum channels, ALenum type, ALvoid *data);
AL_API ALboolean AL_APIENTRY alIsBufferFormatSupportedSOFT(ALenum format);
#endif
#endif

#ifndef AL_SOFT_non_virtual_channels
#define AL_SOFT_non_virtual_channels 1
#define AL_VIRTUAL_CHANNELS_SOFT                 0x1033
#endif

#ifndef AL_SOFT_deferred_updates
#define AL_SOFT_deferred_updates 1
#define AL_DEFERRED_UPDATES_SOFT                 0xC002
typedef ALvoid (AL_APIENTRY*LPALDEFERUPDATESSOFT)(void);
typedef ALvoid (AL_APIENTRY*LPALPROCESSUPDATESSOFT)(void);
#ifdef AL_ALEXT_PROTOTYPES
AL_API ALvoid AL_APIENTRY alDeferUpdatesSOFT(void);
AL_API ALvoid AL_APIENTRY alProcessUpdatesSOFT(void);
#endif
#endif


#if defined(HAVE_STDINT_H)
#include <stdint.h>
typedef int64_t ALint64;
typedef uint64_t ALuint64;
#elif defined(HAVE___INT64)
typedef __int64 ALint64;
typedef unsigned __int64 ALuint64;
#elif (SIZEOF_LONG == 8)
typedef long ALint64;
typedef unsigned long ALuint64;
#elif (SIZEOF_LONG_LONG == 8)
typedef long long ALint64;
typedef unsigned long long ALuint64;
#endif

typedef ptrdiff_t ALintptrEXT;
typedef ptrdiff_t ALsizeiptrEXT;

#ifdef HAVE_GCC_FORMAT
#define PRINTF_STYLE(x, y) __attribute__((format(printf, (x), (y))))
#else
#define PRINTF_STYLE(x, y)
#endif

#if defined(HAVE_RESTRICT)
#define RESTRICT restrict
#elif defined(HAVE___RESTRICT)
#define RESTRICT __restrict
#else
#define RESTRICT
#endif


#ifdef _WIN32

#include <windows.h>

typedef DWORD pthread_key_t;
int pthread_key_create(pthread_key_t *key, void (*callback)(void*));
int pthread_key_delete(pthread_key_t key);
void *pthread_getspecific(pthread_key_t key);
int pthread_setspecific(pthread_key_t key, void *val);

#define HAVE_DYNLOAD 1
void *LoadLib(const char *name);
void CloseLib(void *handle);
void *GetSymbol(void *handle, const char *name);

typedef LONG pthread_once_t;
#define PTHREAD_ONCE_INIT 0
void pthread_once(pthread_once_t *once, void (*callback)(void));

static __inline int sched_yield(void)
{ SwitchToThread(); return 0; }

#else

#include <unistd.h>
#include <assert.h>
#include <pthread.h>
#ifdef HAVE_PTHREAD_NP_H
#include <pthread_np.h>
#endif
#include <sys/time.h>
#include <time.h>
#include <errno.h>

#define IsBadWritePtr(a,b) ((a) == NULL && (b) != 0)

typedef pthread_mutex_t CRITICAL_SECTION;
void InitializeCriticalSection(CRITICAL_SECTION *cs);
void DeleteCriticalSection(CRITICAL_SECTION *cs);
void EnterCriticalSection(CRITICAL_SECTION *cs);
void LeaveCriticalSection(CRITICAL_SECTION *cs);

ALuint timeGetTime(void);
void Sleep(ALuint t);

#if defined(HAVE_DLFCN_H)
#define HAVE_DYNLOAD 1
void *LoadLib(const char *name);
void CloseLib(void *handle);
void *GetSymbol(void *handle, const char *name);
#endif

#endif

#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 1))
typedef ALuint RefCount;
static __inline RefCount IncrementRef(volatile RefCount *ptr)
{ return __sync_add_and_fetch(ptr, 1); }
static __inline RefCount DecrementRef(volatile RefCount *ptr)
{ return __sync_sub_and_fetch(ptr, 1); }

static __inline int ExchangeInt(volatile int *ptr, int newval)
{
    return __sync_lock_test_and_set(ptr, newval);
}
static __inline void *ExchangePtr(void *volatile*ptr, void *newval)
{
    return __sync_lock_test_and_set(ptr, newval);
}
static __inline ALboolean CompExchangeInt(volatile int *ptr, int oldval, int newval)
{
    return __sync_bool_compare_and_swap(ptr, oldval, newval);
}
static __inline ALboolean CompExchangePtr(void *volatile*ptr, void *oldval, void *newval)
{
    return __sync_bool_compare_and_swap(ptr, oldval, newval);
}

#elif defined(__GNUC__) && (defined(__i386__) || defined(__x86_64__))

static __inline int xaddl(volatile int *dest, int incr)
{
    int ret;
    __asm__ __volatile__("lock; xaddl %0,(%1)"
                         : "=r" (ret)
                         : "r" (dest), "0" (incr)
                         : "memory");
    return ret;
}

typedef int RefCount;
static __inline RefCount IncrementRef(volatile RefCount *ptr)
{ return xaddl(ptr, 1)+1; }
static __inline RefCount DecrementRef(volatile RefCount *ptr)
{ return xaddl(ptr, -1)-1; }

static __inline int ExchangeInt(volatile int *dest, int newval)
{
    int ret;
    __asm__ __volatile__("lock; xchgl %0,(%1)"
                         : "=r" (ret)
                         : "r" (dest), "0" (newval)
                         : "memory");
    return ret;
}

static __inline ALboolean CompExchangeInt(volatile int *dest, int oldval, int newval)
{
    int ret;
    __asm__ __volatile__("lock; cmpxchgl %2,(%1)"
                         : "=a" (ret)
                         : "r" (dest), "r" (newval), "0" (oldval)
                         : "memory");
    return ret == oldval;
}

static __inline void *ExchangePtr(void *volatile*dest, void *newval)
{
    void *ret;
    __asm__ __volatile__(
#ifdef __i386__
                         "lock; xchgl %0,(%1)"
#else
                         "lock; xchgq %0,(%1)"
#endif
                         : "=r" (ret)
                         : "r" (dest), "0" (newval)
                         : "memory"
    );
    return ret;
}

static __inline ALboolean CompExchangePtr(void *volatile*dest, void *oldval, void *newval)
{
    void *ret;
    __asm__ __volatile__(
#ifdef __i386__
                         "lock; cmpxchgl %2,(%1)"
#else
                         "lock; cmpxchgq %2,(%1)"
#endif
                         : "=a" (ret)
                         : "r" (dest), "r" (newval), "0" (oldval)
                         : "memory"
    );
    return ret == oldval;
}

#elif defined(_WIN32)

typedef LONG RefCount;
static __inline RefCount IncrementRef(volatile RefCount *ptr)
{ return InterlockedIncrement(ptr); }
static __inline RefCount DecrementRef(volatile RefCount *ptr)
{ return InterlockedDecrement(ptr); }

extern ALbyte LONG_size_does_not_match_int[(sizeof(LONG)==sizeof(int))?1:-1];

static __inline int ExchangeInt(volatile int *ptr, int newval)
{
    union {
        volatile int *i;
        volatile LONG *l;
    } u = { ptr };
    return InterlockedExchange(u.l, newval);
}
static __inline void *ExchangePtr(void *volatile*ptr, void *newval)
{
    return InterlockedExchangePointer(ptr, newval);
}
static __inline ALboolean CompExchangeInt(volatile int *ptr, int oldval, int newval)
{
    union {
        volatile int *i;
        volatile LONG *l;
    } u = { ptr };
    return InterlockedCompareExchange(u.l, newval, oldval) == oldval;
}
static __inline ALboolean CompExchangePtr(void *volatile*ptr, void *oldval, void *newval)
{
    return InterlockedCompareExchangePointer(ptr, newval, oldval) == oldval;
}

#elif defined(__APPLE__)

#include <libkern/OSAtomic.h>

typedef int32_t RefCount;
static __inline RefCount IncrementRef(volatile RefCount *ptr)
{ return OSAtomicIncrement32Barrier(ptr); }
static __inline RefCount DecrementRef(volatile RefCount *ptr)
{ return OSAtomicDecrement32Barrier(ptr); }

static __inline int ExchangeInt(volatile int *ptr, int newval)
{
    /* Really? No regular old atomic swap? */
    int oldval;
    do {
        oldval = *ptr;
    } while(!OSAtomicCompareAndSwap32Barrier(oldval, newval, ptr));
    return oldval;
}
static __inline void *ExchangePtr(void *volatile*ptr, void *newval)
{
    void *oldval;
    do {
        oldval = *ptr;
    } while(!OSAtomicCompareAndSwapPtrBarrier(oldval, newval, ptr));
    return oldval;
}
static __inline ALboolean CompExchangeInt(volatile int *ptr, int oldval, int newval)
{
    return OSAtomicCompareAndSwap32Barrier(oldval, newval, ptr);
}
static __inline ALboolean CompExchangePtr(void *volatile*ptr, void *oldval, void *newval)
{
    return OSAtomicCompareAndSwapPtrBarrier(oldval, newval, ptr);
}

#else
#error "No atomic functions available on this platform!"
typedef ALuint RefCount;
#endif


typedef struct {
    volatile RefCount read_count;
    volatile RefCount write_count;
    volatile ALenum read_lock;
    volatile ALenum read_entry_lock;
    volatile ALenum write_lock;
} RWLock;

void RWLockInit(RWLock *lock);
void ReadLock(RWLock *lock);
void ReadUnlock(RWLock *lock);
void WriteLock(RWLock *lock);
void WriteUnlock(RWLock *lock);


typedef struct UIntMap {
    struct {
        ALuint key;
        ALvoid *value;
    } *array;
    ALsizei size;
    ALsizei maxsize;
    ALsizei limit;
    RWLock lock;
} UIntMap;
extern UIntMap TlsDestructor;

void InitUIntMap(UIntMap *map, ALsizei limit);
void ResetUIntMap(UIntMap *map);
ALenum InsertUIntMapEntry(UIntMap *map, ALuint key, ALvoid *value);
ALvoid *RemoveUIntMapKey(UIntMap *map, ALuint key);
ALvoid *LookupUIntMapKey(UIntMap *map, ALuint key);

static __inline void LockUIntMapRead(UIntMap *map)
{ ReadLock(&map->lock); }
static __inline void UnlockUIntMapRead(UIntMap *map)
{ ReadUnlock(&map->lock); }
static __inline void LockUIntMapWrite(UIntMap *map)
{ WriteLock(&map->lock); }
static __inline void UnlockUIntMapWrite(UIntMap *map)
{ WriteUnlock(&map->lock); }

#include "alListener.h"
#include "alu.h"

#ifdef __cplusplus
extern "C" {
#endif


#define DEFAULT_OUTPUT_RATE        (44100)

#define SPEEDOFSOUNDMETRESPERSEC   (343.3f)
#define AIRABSORBGAINHF            (0.99426f) /* -0.05dB */

#define LOWPASSFREQREF             (5000)


struct Hrtf;


// Find the next power-of-2 for non-power-of-2 numbers.
static __inline ALuint NextPowerOf2(ALuint value)
{
    ALuint powerOf2 = 1;

    if(value)
    {
        value--;
        while(value)
        {
            value >>= 1;
            powerOf2 <<= 1;
        }
    }
    return powerOf2;
}

/* Fast float-to-int conversion. Assumes the FPU is already in round-to-zero
 * mode. */
static __inline ALint fastf2i(ALfloat f)
{
    ALint i;
#if defined(_MSC_VER) && !defined(_WIN64)
    __asm fld f
    __asm fistp i
#elif defined(__GNUC__)
    __asm__ __volatile__("flds %1\n\t"
                         "fistpl %0\n\t"
                         : "=m" (i)
                         : "m" (f));
#else
    i = (ALint)f;
#endif
    return i;
}

/* Fast float-to-uint conversion. Assumes the FPU is already in round-to-zero
 * mode. */
static __inline ALuint fastf2u(ALfloat f)
{ return fastf2i(f); }


enum DevProbe {
    DEVICE_PROBE,
    ALL_DEVICE_PROBE,
    CAPTURE_DEVICE_PROBE
};

typedef struct {
    ALCenum (*OpenPlayback)(ALCdevice*, const ALCchar*);
    void (*ClosePlayback)(ALCdevice*);
    ALCboolean (*ResetPlayback)(ALCdevice*);
    void (*StopPlayback)(ALCdevice*);

    ALCenum (*OpenCapture)(ALCdevice*, const ALCchar*);
    void (*CloseCapture)(ALCdevice*);
    void (*StartCapture)(ALCdevice*);
    void (*StopCapture)(ALCdevice*);
    ALCenum (*CaptureSamples)(ALCdevice*, void*, ALCuint);
    ALCuint (*AvailableSamples)(ALCdevice*);
} BackendFuncs;

struct BackendInfo {
    const char *name;
    ALCboolean (*Init)(BackendFuncs*);
    void (*Deinit)(void);
    void (*Probe)(enum DevProbe);
    BackendFuncs Funcs;
};

ALCboolean alc_alsa_init(BackendFuncs *func_list);
void alc_alsa_deinit(void);
void alc_alsa_probe(enum DevProbe type);
ALCboolean alc_oss_init(BackendFuncs *func_list);
void alc_oss_deinit(void);
void alc_oss_probe(enum DevProbe type);
ALCboolean alc_solaris_init(BackendFuncs *func_list);
void alc_solaris_deinit(void);
void alc_solaris_probe(enum DevProbe type);
ALCboolean alc_sndio_init(BackendFuncs *func_list);
void alc_sndio_deinit(void);
void alc_sndio_probe(enum DevProbe type);
ALCboolean alcMMDevApiInit(BackendFuncs *func_list);
void alcMMDevApiDeinit(void);
void alcMMDevApiProbe(enum DevProbe type);
ALCboolean alcDSoundInit(BackendFuncs *func_list);
void alcDSoundDeinit(void);
void alcDSoundProbe(enum DevProbe type);
ALCboolean alcWinMMInit(BackendFuncs *FuncList);
void alcWinMMDeinit(void);
void alcWinMMProbe(enum DevProbe type);
ALCboolean alc_pa_init(BackendFuncs *func_list);
void alc_pa_deinit(void);
void alc_pa_probe(enum DevProbe type);
ALCboolean alc_wave_init(BackendFuncs *func_list);
void alc_wave_deinit(void);
void alc_wave_probe(enum DevProbe type);
ALCboolean alc_pulse_init(BackendFuncs *func_list);
void alc_pulse_deinit(void);
void alc_pulse_probe(enum DevProbe type);
ALCboolean alc_ca_init(BackendFuncs *func_list);
void alc_ca_deinit(void);
void alc_ca_probe(enum DevProbe type);
ALCboolean alc_opensl_init(BackendFuncs *func_list);
void alc_opensl_deinit(void);
void alc_opensl_probe(enum DevProbe type);
ALCboolean alc_null_init(BackendFuncs *func_list);
void alc_null_deinit(void);
void alc_null_probe(enum DevProbe type);
ALCboolean alc_loopback_init(BackendFuncs *func_list);
void alc_loopback_deinit(void);
void alc_loopback_probe(enum DevProbe type);


/* Device formats */
enum DevFmtType {
    DevFmtByte   = ALC_BYTE_SOFT,
    DevFmtUByte  = ALC_UNSIGNED_BYTE_SOFT,
    DevFmtShort  = ALC_SHORT_SOFT,
    DevFmtUShort = ALC_UNSIGNED_SHORT_SOFT,
    DevFmtFloat  = ALC_FLOAT_SOFT
};
enum DevFmtChannels {
    DevFmtMono   = ALC_MONO_SOFT,
    DevFmtStereo = ALC_STEREO_SOFT,
    DevFmtQuad   = ALC_QUAD_SOFT,
    DevFmtX51    = ALC_5POINT1_SOFT,
    DevFmtX61    = ALC_6POINT1_SOFT,
    DevFmtX71    = ALC_7POINT1_SOFT,

    /* Similar to 5.1, except using the side channels instead of back */
    DevFmtX51Side = 0x80000000 | ALC_5POINT1_SOFT
};

ALuint BytesFromDevFmt(enum DevFmtType type);
ALuint ChannelsFromDevFmt(enum DevFmtChannels chans);
static __inline ALuint FrameSizeFromDevFmt(enum DevFmtChannels chans,
                                           enum DevFmtType type)
{
    return ChannelsFromDevFmt(chans) * BytesFromDevFmt(type);
}


extern const struct EffectList {
    const char *name;
    int type;
    const char *ename;
    ALenum val;
} EffectList[];


struct ALCdevice_struct
{
    volatile RefCount ref;

    ALCboolean   Connected;
    ALboolean    IsCaptureDevice;
    ALboolean    IsLoopbackDevice;

    CRITICAL_SECTION Mutex;

    ALuint       Frequency;
    ALuint       UpdateSize;
    ALuint       NumUpdates;
    enum DevFmtChannels FmtChans;
    enum DevFmtType     FmtType;

    ALCchar      *szDeviceName;

    volatile ALCenum LastError;

    // Maximum number of sources that can be created
    ALuint       MaxNoOfSources;
    // Maximum number of slots that can be created
    ALuint       AuxiliaryEffectSlotMax;

    ALCuint      NumMonoSources;
    ALCuint      NumStereoSources;
    ALuint       NumAuxSends;

    // Map of Buffers for this device
    UIntMap BufferMap;

    // Map of Effects for this device
    UIntMap EffectMap;

    // Map of Filters for this device
    UIntMap FilterMap;

    /* HRTF filter tables */
    const struct Hrtf *Hrtf;

    // Stereo-to-binaural filter
    struct bs2b *Bs2b;
    ALCint       Bs2bLevel;

    // Device flags
    ALuint       Flags;

    // Dry path buffer mix
    ALfloat DryBuffer[BUFFERSIZE][MAXCHANNELS];

    enum Channel DevChannels[MAXCHANNELS];

    enum Channel Speaker2Chan[MAXCHANNELS];
    ALfloat PanningLUT[LUT_NUM][MAXCHANNELS];
    ALuint  NumChan;

    ALfloat ClickRemoval[MAXCHANNELS];
    ALfloat PendingClicks[MAXCHANNELS];

    // Contexts created on this device
    ALCcontext *volatile ContextList;

    BackendFuncs *Funcs;
    void         *ExtraData; // For the backend's use

    ALCdevice *volatile next;
};

#define ALCdevice_OpenPlayback(a,b)      ((a)->Funcs->OpenPlayback((a), (b)))
#define ALCdevice_ClosePlayback(a)       ((a)->Funcs->ClosePlayback((a)))
#define ALCdevice_ResetPlayback(a)       ((a)->Funcs->ResetPlayback((a)))
#define ALCdevice_StopPlayback(a)        ((a)->Funcs->StopPlayback((a)))
#define ALCdevice_OpenCapture(a,b)       ((a)->Funcs->OpenCapture((a), (b)))
#define ALCdevice_CloseCapture(a)        ((a)->Funcs->CloseCapture((a)))
#define ALCdevice_StartCapture(a)        ((a)->Funcs->StartCapture((a)))
#define ALCdevice_StopCapture(a)         ((a)->Funcs->StopCapture((a)))
#define ALCdevice_CaptureSamples(a,b,c)  ((a)->Funcs->CaptureSamples((a), (b), (c)))
#define ALCdevice_AvailableSamples(a)    ((a)->Funcs->AvailableSamples((a)))

// Duplicate stereo sources on the side/rear channels
#define DEVICE_DUPLICATE_STEREO                  (1<<0)
// Frequency was requested by the app or config file
#define DEVICE_FREQUENCY_REQUEST                 (1<<1)
// Channel configuration was requested by the config file
#define DEVICE_CHANNELS_REQUEST                  (1<<2)

// Specifies if the device is currently running
#define DEVICE_RUNNING                           (1<<31)

#define LookupBuffer(m, k) ((struct ALbuffer*)LookupUIntMapKey(&(m)->BufferMap, (k)))
#define LookupEffect(m, k) ((struct ALeffect*)LookupUIntMapKey(&(m)->EffectMap, (k)))
#define LookupFilter(m, k) ((struct ALfilter*)LookupUIntMapKey(&(m)->FilterMap, (k)))
#define RemoveBuffer(m, k) ((struct ALbuffer*)RemoveUIntMapKey(&(m)->BufferMap, (k)))
#define RemoveEffect(m, k) ((struct ALeffect*)RemoveUIntMapKey(&(m)->EffectMap, (k)))
#define RemoveFilter(m, k) ((struct ALfilter*)RemoveUIntMapKey(&(m)->FilterMap, (k)))


struct ALCcontext_struct
{
    volatile RefCount ref;

    ALlistener  Listener;

    UIntMap SourceMap;
    UIntMap EffectSlotMap;

    ALenum LastError;

    volatile ALenum UpdateSources;

    volatile enum DistanceModel DistanceModel;
    volatile ALboolean SourceDistanceModel;

    volatile ALfloat DopplerFactor;
    volatile ALfloat DopplerVelocity;
    volatile ALfloat flSpeedOfSound;
    volatile ALenum  DeferUpdates;

    struct ALsource **ActiveSources;
    ALsizei           ActiveSourceCount;
    ALsizei           MaxActiveSources;

    struct ALeffectslot **ActiveEffectSlots;
    ALsizei               ActiveEffectSlotCount;
    ALsizei               MaxActiveEffectSlots;

    ALCdevice  *Device;
    const ALCchar *ExtensionList;

    ALCcontext *volatile next;
};

#define LookupSource(m, k) ((struct ALsource*)LookupUIntMapKey(&(m)->SourceMap, (k)))
#define LookupEffectSlot(m, k) ((struct ALeffectslot*)LookupUIntMapKey(&(m)->EffectSlotMap, (k)))
#define RemoveSource(m, k) ((struct ALsource*)RemoveUIntMapKey(&(m)->SourceMap, (k)))
#define RemoveEffectSlot(m, k) ((struct ALeffectslot*)RemoveUIntMapKey(&(m)->EffectSlotMap, (k)))

ALCcontext *GetContextRef(void);

void ALCcontext_IncRef(ALCcontext *context);
void ALCcontext_DecRef(ALCcontext *context);

void AppendDeviceList(const ALCchar *name);
void AppendAllDeviceList(const ALCchar *name);
void AppendCaptureDeviceList(const ALCchar *name);

ALCvoid LockDevice(ALCdevice *device);
ALCvoid UnlockDevice(ALCdevice *device);
ALCvoid LockContext(ALCcontext *context);
ALCvoid UnlockContext(ALCcontext *context);

ALvoid *StartThread(ALuint (*func)(ALvoid*), ALvoid *ptr);
ALuint StopThread(ALvoid *thread);

typedef struct RingBuffer RingBuffer;
RingBuffer *CreateRingBuffer(ALsizei frame_size, ALsizei length);
void DestroyRingBuffer(RingBuffer *ring);
ALsizei RingBufferSize(RingBuffer *ring);
void WriteRingBuffer(RingBuffer *ring, const ALubyte *data, ALsizei len);
void ReadRingBuffer(RingBuffer *ring, ALubyte *data, ALsizei len);

void ReadALConfig(void);
void FreeALConfig(void);
int ConfigValueExists(const char *blockName, const char *keyName);
const char *GetConfigValue(const char *blockName, const char *keyName, const char *def);
int GetConfigValueBool(const char *blockName, const char *keyName, int def);
int ConfigValueStr(const char *blockName, const char *keyName, const char **ret);
int ConfigValueInt(const char *blockName, const char *keyName, int *ret);
int ConfigValueUInt(const char *blockName, const char *keyName, unsigned int *ret);
int ConfigValueFloat(const char *blockName, const char *keyName, float *ret);

void SetRTPriority(void);

void SetDefaultChannelOrder(ALCdevice *device);
void SetDefaultWFXChannelOrder(ALCdevice *device);

const ALCchar *DevFmtTypeString(enum DevFmtType type);
const ALCchar *DevFmtChannelsString(enum DevFmtChannels chans);

#define HRIR_BITS        (5)
#define HRIR_LENGTH      (1<<HRIR_BITS)
#define HRIR_MASK        (HRIR_LENGTH-1)
void InitHrtf(void);
void FreeHrtf(void);
const struct Hrtf *GetHrtf(ALCdevice *device);
ALfloat CalcHrtfDelta(ALfloat oldGain, ALfloat newGain, const ALfloat olddir[3], const ALfloat newdir[3]);
void GetLerpedHrtfCoeffs(const struct Hrtf *Hrtf, ALfloat elevation, ALfloat azimuth, ALfloat gain, ALfloat (*coeffs)[2], ALuint *delays);
ALuint GetMovingHrtfCoeffs(const struct Hrtf *Hrtf, ALfloat elevation, ALfloat azimuth, ALfloat gain, ALfloat delta, ALint counter, ALfloat (*coeffs)[2], ALuint *delays, ALfloat (*coeffStep)[2], ALint *delayStep);

void al_print(const char *func, const char *fmt, ...) PRINTF_STYLE(2,3);
#define AL_PRINT(...) al_print(__FUNCTION__, __VA_ARGS__)

extern FILE *LogFile;
enum LogLevel {
    NoLog,
    LogError,
    LogWarning,
    LogTrace,
    LogRef
};
extern enum LogLevel LogLevel;

#define TRACEREF(...) do {                                                    \
    if(LogLevel >= LogRef)                                                    \
        AL_PRINT(__VA_ARGS__);                                                \
} while(0)

#define TRACE(...) do {                                                       \
    if(LogLevel >= LogTrace)                                                  \
        AL_PRINT(__VA_ARGS__);                                                \
} while(0)

#define WARN(...) do {                                                        \
    if(LogLevel >= LogWarning)                                                \
        AL_PRINT(__VA_ARGS__);                                                \
} while(0)

#define ERR(...) do {                                                         \
    if(LogLevel >= LogError)                                                  \
        AL_PRINT(__VA_ARGS__);                                                \
} while(0)


extern ALint RTPrioLevel;

#ifdef __cplusplus
}
#endif

#endif
