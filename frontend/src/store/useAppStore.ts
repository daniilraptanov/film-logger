import { create } from 'zustand'

type AppState = {
    isLoading: boolean
    setLoading: (value: boolean) => void
}

export const useAppStore = create<AppState>((set) => ({
    isLoading: false,
    setLoading: (value: boolean) => set({ isLoading: value }),
}))


export function withLoading<T extends (...args: any[]) => Promise<any>>(fn: T): T {
  return (async (...args: Parameters<T>): Promise<ReturnType<T>> => {
    const { setLoading } = useAppStore.getState();
    setLoading(true)
    try {
      return await fn(...args)
    } finally {
      setLoading(false)
    }
  }) as T;
}

