import ky from "ky";

export abstract class ApiService {
    API = ky.create({
        prefixUrl: import.meta.env.VITE_API_URL,
    });
}
